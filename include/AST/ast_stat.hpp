#ifndef AST_STAT_HPP
#define AST_STAT_HPP

#include "Node.hpp"
#include "ast_expression.hpp"
#include "ast_binOp.hpp"
#include "ast_unaryOp.hpp"

class stat : public Node {
public:
    virtual void codegen(wrapper& code) const
    {
        code.push_instr(new notWorking("statement"));
    }
};

class stats : public stat {
private:
    const Node* statemants;
public:
    stats(const Node* _stats) :
        statemants(_stats) {}
    
    ~stats()
    {
        delete statemants;
    }

    virtual void codegen(wrapper& code) const override
    {
        code.create_Scope();
        statemants->codegen(code);
        code.destroy_Scope();
    }
};

class decls : public stat {
private:
    const Node* decs;
public:
    decls(const Node* _decs) :
        decs(_decs) {}

    ~decls()
    {
        delete decs;
    }

    virtual void codegen(wrapper& code) const override
    {
        code.create_Scope();

        decs->codegen(code);
        
        code.destroy_Scope();
    }
};

class decsStats : public stat {
private:
    const Node* decs;
    const Node* stats;
public:
    decsStats(const Node* _decs, const Node* _stats) :
        decs(_decs),
        stats(_stats) {}

    ~decsStats()
    {
        delete decs;
        delete stats;
    }

    virtual void codegen(wrapper& code) const override
    {
        code.create_Scope();

        decs->codegen(code);
        stats->codegen(code);

        code.destroy_Scope();
    }
};

class statList : public stat {
private:
    const Node* left;
    const Node* right;
public:
    statList(const Node* _left, const Node* _right) :
        left(_left),
        right(_right) {}

    ~statList()
    {
        delete left;
        delete right;
    }

    virtual void codegen(wrapper& code) const
    {
        left->codegen(code);
        right->codegen(code);
    }
};

class emptyStat : public stat {
public:
    virtual void codegen(wrapper& code) const override
    {
        code.push_instr(new nop());
    }
};

class exprStat : public stat {
private:
    const expression* expr;
public:
    exprStat(const expression* _expr) :
        expr(_expr) {}

    ~exprStat()
    {
        delete expr;
    }

    virtual void codegen(wrapper& code) const override
    {
        expr->codegen(code);
    }
};

class ifStat : public stat {
private:
    const expression* cond;
    const Node* stat;
public:
    ifStat(const expression* _cond, const Node* _stat) :
        cond(_cond),
        stat(_stat) {}

    ~ifStat()
    {
        delete cond;
        delete stat;
    }

const expression* get_cond() const
    {
        return cond;
    }

    const Node* get_stat() const
    {
        return stat;
    }

    virtual void codegen(wrapper& code) const override
    {
        std::string end = code.get_Label();
        code.set_DestReg(RR);
        cond->codegen(code);
        code.push_instr(new branch("beq", RR, ZR, end));
        code.push_instr(new nop());
        stat->codegen(code);
        code.push_instr(new label(end));
    }

};

class ifStatElse : public ifStat {
private:
    const Node* elseStat;
public:
    ifStatElse(const expression* _cond, const Node* _stat, const Node* _elseStat) :
        ifStat(_cond, _stat),
        elseStat(_elseStat) {}

    ~ifStatElse()
    {
        delete elseStat;
    }

    virtual void codegen(wrapper& code) const override
    {
        std::string elselab = code.get_Label();
        std::string end = code.get_Label();

        code.set_DestReg(RR);
        ifStat::get_cond()->codegen(code);
        code.push_instr(new branch("beq", RR, ZR, elselab));
        code.push_instr(new nop());

        ifStat::get_stat()->codegen(code);
        code.push_instr(new jl("b", end));
        code.push_instr(new nop());

        code.push_instr(new label(elselab));
        elseStat->codegen(code);

        code.push_instr(new label(end));
    }
};

class returnStat : public stat {
private:
    const expression* expr;
public:
    returnStat(const expression* _expr):
        expr(_expr) {}

    ~returnStat()
    {
        delete expr;
    }

    virtual void codegen(wrapper& code) const override
    {
        code.set_DestReg(RR);
        expr->codegen(code);
        code.push_instr(new jl("b", code.get_ReturnLabel()));
        code.push_instr(new nop());
    }
};

#endif