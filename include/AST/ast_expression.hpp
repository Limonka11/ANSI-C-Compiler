#ifndef AST_EXPRESSION_HPP
#define AST_EXPRESSION_HPP

#include <vector>
#include "Node.hpp"
#include "ast_int.hpp"
#include "var_type.hpp"

class expression : public Node {
public:
    virtual std::string evaluate() const { exit(1); }

    virtual bool is_list() const { return false; }

    virtual bool is_identifier() const { return false; }

    virtual bool has_params() const { return false; }

    virtual void codegen(wrapper& code) const
    {
        code.push_instr(new notWorking("expression"));
    }

    /*
    virtual bool check_type(wrapper& code) const
    {
        (void)code;
        exit(1);
    }
    */
};

class voidExpr : public expression
{
    virtual void codegen(wrapper& code) const override{ (void)code; }
};

class identifier : public expression {
private:
    std::string id;
public:
    identifier(std::string* _id) :
        id(*_id) { delete _id; }

    std::string get_id() const { return id; }

    virtual bool is_identifier() const { return true; }

    const variable* get_var(wrapper& code) const
    {
        const variable* var = code.get_CurrentScope()->getVar(id);
        if (var == NULL)
        {
            exit(1);
        }
        return var;
    }

    virtual void codegen(wrapper& code) const
    {
        const variable* var = get_var(code);

        var->load(code, code.get_DestReg());
    }

    /*
    virtual bool check_type(wrapper& code) const
    {
        const variable* var = code.get_CurrentScope()->getVar(id);
        if(var->get_type()->is_float())
        {
            return true;
        } else {
            return false;
        }
    }
    */
};

class constant : public expression {
private:
    std::string val;
public:
    constant(std::string* _val) :
        val(*_val) { delete _val; }

    std::string get_val() const
    {
        return val;
    }

    virtual std::string evaluate() const
    {
        return val;
    }
};

class int_const : public constant {
public:
    int_const(std::string* _val) :
        constant(_val) {}

    int int_value() const
    {
        return std::stol(constant::get_val(), nullptr, 0);
    }

    virtual void codegen(wrapper& code) const override
    {

        int val = int_value();
        uint8_t reg = code.get_DestReg();

        code.push_instr(new li(reg, val));
    }
};

class float_const : public constant {
public:
    float_const(std::string* _val) :
        constant(_val) {}

    float float_value() const
    {
        return std::stof(constant::get_val());
    }

    virtual void codegen(wrapper& code) const override
    {

        float val = float_value();
        uint8_t reg = code.get_DestReg();

        code.push_instr(new li_S(reg, val));
        //code.push_instr(new twoRegsFloat("mfc1", reg, RR));
    }

};

class assignExpr : public expression {
private:
    const identifier* left;
    const expression* right;
public:
    assignExpr(const expression* _left, const expression* _right) :
        right(_right)
    {
        if (_left->is_identifier())
        {
            left = (identifier*)_left;
        } else {
            exit(1);
        }
    }

    ~assignExpr()
    {
        delete left;
        delete right;
    }

    const identifier* get_Left() const
    {
        return left;
    }

    const expression* get_Right() const
    {
        return right;
    }

    const variable* getVar(wrapper& code) const
    {
        std::string id = left->get_id();
        scope* curScope = code.get_CurrentScope();
        const variable* var = curScope->getVar(id);
        
        if (var == NULL)
        {
            exit(1);
        }
        return var;
    }

    void codegen_helper(wrapper& code, int reg_left, int reg_right) const
    {
        code.set_DestReg(reg_right);
        right->codegen(code);

        const variable* var = getVar(code);
        var->load(code, reg_left);
    }

    void codegen_assign(wrapper& code, int reg) const
    {
        getVar(code)->store(code, reg);
    }
};

class regularAssign : public assignExpr {
public:
    regularAssign(const expression* _left, const expression* _right) :
        assignExpr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();
        
        assignExpr::get_Right()->codegen(code);

        codegen_assign(code, reg);
    }
};

class functionCall : public expression {
private:
    const identifier* idExpr;
public:
    functionCall(const expression* _idExpr)
    {
        if (_idExpr->is_identifier())
        {
            idExpr = (identifier*)_idExpr;
        } else {
            exit(1);
        }
    }

    ~functionCall()
    {
        delete idExpr;
    }

    const identifier* get_idExpr() const
    {
        return idExpr;
    }

    virtual void codegen(wrapper& code) const override
    {

        code.save_Reg(31);

        code.push_instr(new dir("option", "pic0"));
        code.push_instr(new jl("jal", idExpr->get_id()));
        code.push_instr(new nop());
        code.push_instr(new dir("option", "pic2"));

        if (code.get_DestReg() != RR)
        {
            code.push_instr(new twoRegs("move", code.get_DestReg(), RR));
        }
    }
};

class functionCallParams : public functionCall {
private:
    const expression* args;
public:
    functionCallParams(const expression* _idExpr, const expression* _args) :
        functionCall(_idExpr),
        args(_args) {}

    ~functionCallParams()
    {
        delete args;
    }

    virtual bool has_params() const override { return true; }

    virtual void codegen(wrapper& code) const override
    {


        int reg = code.get_DestReg();

        code.push_ParamIndex();
        code.reset_ParamIndex();
        code.set_DestReg(PARAM_REGS[0]);
        args->codegen(code);
        code.set_FP(code.get_ParamIndex() * 4, frame_params);
        code.set_DestReg(reg);
        functionCall::codegen(code);
        code.pop_ParamIndex();

    }
};

class argExprList : public expression {
private:
    const expression* left;
    const expression* right;
public:
    argExprList(const expression* _left, const expression* _right) :
        left(_left),
        right(_right) {}

    ~argExprList()
    {
        delete left;
        delete right;
    }

    virtual bool is_list() const { return true; }

    void param_setup(wrapper& code, const expression* arg) const
    {
        int par = code.get_ParamIndex();
        if (par < NUM_PARAM_REGS)
        {
            code.set_DestReg(PARAM_REGS[par]);
        } else {
            code.set_DestReg(RR);
        }

        int savedRegs;

        if (par < NUM_PARAM_REGS)
        {
            savedRegs = par;
        } else {
            savedRegs = NUM_PARAM_REGS;
        }

        int savedFp = code.get_FP(frame_temps);

        if (arg->has_params())
        {
            for (int i = 0; i < savedRegs; i++)
            {
                code.incr_FP(4, frame_temps);
                code.push_tmpOffset(new memoryOffset("sw", PARAM_REGS[i], savedFp + 4 * i, FP), frame_temps);
            }
        }

        arg->codegen(code);

        if (arg->has_params())
        {
            for (int i = 0; i < savedRegs; i++)
            {
                code.push_tmpOffset(new memoryOffset("lw", PARAM_REGS[i], savedFp + 4 * i, FP), frame_temps);
                code.decr_FP(4, frame_temps);
            }
        }

        if (par >= NUM_PARAM_REGS)
        {
            int fp = 4 * par;
            code.push_tmpOffset(new memoryOffset("sw", RR, fp, FP), frame_params);
            code.set_FP(fp, frame_params);
        }
    }

    virtual void codegen(wrapper& code) const override
    {
        if (left->is_list())
        {
            left->codegen(code);
        } else {
            param_setup(code, left);
        }

        code.incr_ParamIndex();

        if (right->is_list())
        {
            right->codegen(code);
        } else {
            param_setup(code, right);
        }
    }
};
#endif