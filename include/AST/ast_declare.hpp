#ifndef AST_DECLARE_HPP
#define AST_DECLARE_HPP

#include "Node.hpp"
#include "ast_loop.hpp"
#include "ast_initializer.hpp"
#include "ast_int.hpp"

class declarator : public Node {
public:
    virtual std::string get_id() const
    {
        return "";
    }

    virtual bool is_var() const
    {
        return false;
    }

    virtual void codegen(wrapper& code) const { (void)code; }

    virtual void local(wrapper& code, const specifier* spec) const
    {
        (void)code;
        (void)spec;
        exit(1);
    }

    virtual void localParam(wrapper& code, const specifier* spec, int pos, bool set = true) const
    {
        (void)code;
        (void)spec;
        (void)pos;
        (void)set;
        exit(1);
    }

    virtual void global(wrapper& code, const specifier* spec) const
    {
        (void)code;
        (void)spec;
        exit(1);
    }

};

class idDecl : public declarator {
private:
    std::string id;
public:
    idDecl(std::string _id) :
        id(_id) {}

    virtual std::string get_id() const override
    {
        return id;
    }

    void unsuccessfulDecl() const
    {
        exit(1);
    }
};

class declaratorList : public declarator {
private:
    const declarator* left;
    const declarator* right;
public:
    declaratorList(const declarator* _left, const declarator* _right) :
        left(_left),
        right(_right) {}

    ~declaratorList()
    {
        delete left;
        delete right;
    }

    virtual void codegen(wrapper& code) const override
    {
        (void)code;
    }

    virtual void local(wrapper& code, const specifier* spec) const override
    {
        left->local(code, spec);
        right->local(code, spec);
    }

        virtual void global(wrapper& code, const specifier* spec) const override
    {
        left->global(code, spec);
        right->global(code, spec);
    }

    virtual void localParam(wrapper& code, const specifier* spec, int pos, bool set = true) const override
    {
        left->localParam(code, spec, pos, set);
        right->localParam(code, spec, pos, set);
    }
};

//name of var
class varDeclarator : public idDecl {
public:
    varDeclarator(std::string* _id) :
        idDecl(*_id) { delete _id; }

    virtual bool is_var() const
    {
        return true;
    }

    void declare(wrapper& code, variable* var, bool set = true) const
    {
        if(!code.get_CurrentScope()->declare(idDecl::get_id(), var))
        {
            idDecl::unsuccessfulDecl();
        }

        if (set)
        {
            var->store(code, code.get_DestReg());
        }
    }

    virtual void local(wrapper& code, const specifier* spec) const override
    {
        localVariable* var = new localVariable(code, spec);
        declare(code, var);
    }

    virtual void global(wrapper& code, const specifier* spec) const override
    {
        std::string name = idDecl::get_id();

        code.push_instr(new dir("globl", name));
        code.push_instr(new dir("data", ""));
        code.push_instr(new label(name));

        globalVariable* var = new globalVariable(name, spec);

        declare(code, var, false);
    }

    virtual void localParam(wrapper& code, const specifier* spec, int pos, bool set = true) const override
    {
        localVariableParam* var = new localVariableParam(code, spec, pos);
        declare(code, var, set);
    }
};

//int x=5
class initDeclarator : public declarator {
private:
    const declarator* decl;
    const initial* val;
public:
    initDeclarator(const declarator* _decl, const initial* _val) :
        decl(_decl),
        val(_val) {}

    ~initDeclarator()
    {
        delete decl;
        delete val;
    }

    virtual std::string get_id() const override
    {
        return decl->get_id();
    }


    virtual void local(wrapper& code, const specifier* spec) const override
    {
        val->codegen(code);
        decl->local(code, spec);
    }

    virtual void global(wrapper& code, const specifier* spec) const override
    {
        decl->global(code, spec);
        std::string tmp = val->get_expr()->evaluate();
        code.push_instr(new dir("word", tmp));
    }
};

class voidDecl : public Node {
public:

    virtual void codegen(wrapper& code) const override { (void)code; }
};

//int x
class declaration : public Node {
private:
    const specifier* specs;
    const declarator* decs;
public:
    declaration(const specifier* _specs, const declarator* _decs) :
        specs(_specs),
        decs(_decs) {}

    ~declaration()
    {
        delete specs;
        delete decs;
    }

    virtual void codegen(wrapper& code) const
    {
        if (code.get_CurrentScope()->is_global())
        {
            decs->global(code, specs);
        } else {
            decs->local(code, specs);
        }
    }
};

class declarationList : public Node {
private:
    const Node* left;
    const Node* right;
public:
    declarationList(const Node* _left, const Node* _right) :
        left(_left),
        right(_right) {}

    ~declarationList()
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

class arrayDecl : public declarator {
private:
    const declarator* decl;
    const expression* expr;
public: arrayDecl(const declarator* _decl, const expression* _expr) :
    decl(_decl),
    expr(_expr) {}

    virtual void local(wrapper& code, const specifier* type) const override
    {
        const specifier* arrType = new array_t(std::stol(expr->evaluate()), type);

        if (decl->is_var()) 
        {
            int addr = code.get_FP(frame_vars);

            code.push_tmpOffset(new twoRegsImm("addiu", RR, FP, addr), frame_vars);
        }

        decl->local(code, arrType);
        
    }

    virtual void global(wrapper& code, const specifier* type) const override
    {
        (void)code;
        (void)type;
        exit(1);
    }
};

#endif