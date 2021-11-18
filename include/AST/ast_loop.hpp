#ifndef AST_LOOP_HPP
#define AST_LOOP_HPP

#include "ast_stat.hpp"

class whileLoop : public stat {
private:
    const expression* cond;
    const Node* stat;
public:
    whileLoop(const expression* _cond, const Node* _stat):
        cond(_cond),
        stat(_stat) {}
    
    ~whileLoop()
    {
        delete cond;
        delete stat;
    }

    virtual void codegen(wrapper& code) const override
    {
        std::string start = code.get_Label();

        std::string eval = code.get_Label();

        std::string end = code.get_Label();

        code.push_Break(end);

        code.push_Continue(eval);

        code.push_instr(new jl("b", eval));

        code.push_instr(new nop());

        code.push_instr(new label(start));
        stat->codegen(code);

        code.push_instr(new label(eval));
        code.set_DestReg(RR);

        cond->codegen(code);

        code.push_instr(new branch("bne", RR, ZR, start));
        code.push_instr(new nop());

        code.pop_Break();
        code.pop_Continue();
        code.push_instr(new label(end));
    }
};



class forLoop : public stat {
private:
    const expression* first;
    const expression* second;
    const expression* third;
    const Node* stat;
public:
    forLoop(const expression* _first, const expression* _second, const expression* _third, const Node* _stat) :
        first(_first),
        second(_second),
        third(_third),
        stat(_stat) {}

    ~forLoop()
    {
        delete first;
        delete second;
        delete third;
        delete stat;
    }

    virtual void codegen(wrapper& code) const override
    {
        std::string begin = code.get_Label();

        std::string eval = code.get_Label();

        std::string end = code.get_Label();

        std::string cont = code.get_Label();

        code.push_Break(end);
        code.push_Continue(cont);

        first->codegen(code);
        code.push_instr(new jl("b", eval));
        code.push_instr(new nop());

        code.push_instr(new label(begin));

        stat->codegen(code);

        code.push_instr(new label(cont));
        third->codegen(code);

        code.push_instr(new label(eval));

        code.set_DestReg(RR);
        second->codegen(code);

        code.push_instr(new branch("bne", RR, ZR, begin));

        code.push_instr(new nop());

        code.pop_Break();

        code.pop_Continue();

        code.push_instr(new label(end));
    }
};

class loopContinue : public stat {
public:
        virtual void codegen(wrapper& code) const override
        {
            std::string contLabel = code.get_TopContinue();

            code.push_instr(new jl("b", contLabel));
            code.push_instr(new nop());
        }
};

class loopBreak : public stat {
public:
    virtual void codegen(wrapper& code) const override
    {
        std::string Label = code.get_TopBreak();

        code.push_instr(new jl("b", Label));
        code.push_instr(new nop());
    }
};

#endif