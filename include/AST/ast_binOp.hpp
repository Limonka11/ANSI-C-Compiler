#ifndef AST_BINOP_HPP
#define AST_BINOP_HPP

#include "ast_expression.hpp"

class bin_Expr : public expression {
private:
    const expression* left;
    const expression* right;
public:
    bin_Expr(const expression* _left, const expression* _right) :
        left(_left),
        right(_right) {}

    ~bin_Expr()
    {
        delete left;
        delete right;
    }

    const expression* get_Left() const
    {
        return left;
    }

    const expression* get_Right() const
    {
        return right;
    }

    void codegen_helper(wrapper& code, uint8_t dest_left, uint8_t dest_right) const
    {
        code.set_DestReg(dest_left);
        left->codegen(code);

        int fp = code.incr_FP(4, frame_temps);

        //if(left->check_type(code))
        //{
        //code.push_tmpOffset(new memoryOffsetFloat("swc1", dest_left, fp, FP), frame_temps);
        //} else {
        code.push_tmpOffset(new memoryOffset("sw", dest_left, fp, FP), frame_temps);
        //}
        code.set_DestReg(dest_right);
        right->codegen(code);

        //if(left->check_type(code))
        //{
        //code.push_tmpOffset(new memoryOffsetFloat("lwc1", dest_left, fp, FP), frame_temps);
        //} else {
        code.push_tmpOffset(new memoryOffset("lw", dest_left, fp, FP), frame_temps);
        //}
        code.decr_FP(4, frame_temps);
    }
};

class add_Expr : public bin_Expr {
public:
    add_Expr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) + std::stol(right, nullptr, 0));
    }

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        //if((bin_Expr::get_Left()->check_type(code)) || (bin_Expr::get_Right()->check_type(code)))
        //{
        //    code.push_instr(new threeRegsFloat("add.s", reg, RR, RR + 1));
        //    code.push_instr(new twoRegsFloat("mov.s", FRR , RR));
        //} else {
        code.push_instr(new threeRegs("addu", reg, RR, RR + 1));
        //}
    }
};

class sub_Expr : public bin_Expr {
public:
    sub_Expr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) - std::stol(right, nullptr, 0));
    }

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("sub", reg, RR, RR + 1));
    }
};

class mult_Expr : public bin_Expr {
public:
    mult_Expr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) * std::stol(right, nullptr, 0));
    }

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new twoRegs("mult", RR, RR + 1));
        code.push_instr(new singleReg("mflo", reg));
    }
};

class div_Expr : public bin_Expr {
public:
    div_Expr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new twoRegs("div", RR, RR + 1));

        code.push_instr(new singleReg("mflo", reg));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) / std::stol(right, nullptr, 0));
    }
};

class left_shift : public bin_Expr {
public:
    left_shift(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("sll", reg, RR, RR + 1));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) << std::stol(right, nullptr, 0));
    }
};

class right_shift : public bin_Expr {
public:
    right_shift(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

        virtual void codegen(wrapper& code) const override
        {
            int reg = code.get_DestReg();

            bin_Expr::codegen_helper(code, RR, RR + 1);

            code.push_instr(new threeRegs("sra", reg, RR, RR + 1));
        }

        virtual std::string evaluate() const
        {
            std::string left = bin_Expr::get_Left()->evaluate();
            std::string right = bin_Expr::get_Right()->evaluate();
            return std::to_string(std::stol(left, nullptr, 0) >> std::stol(right, nullptr, 0));
        }
};

class lessThanExpr : public bin_Expr {
public:
    lessThanExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {

        int tmp = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("slt", tmp, RR, RR + 1));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) < std::stol(right, nullptr, 0));
    }
};

class equalToExpr : public bin_Expr {
public:
    equalToExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        std::string equal = code.get_Label();
        std::string end = code.get_Label();

        code.push_instr(new branch("beq", RR, RR + 1, equal));
        code.push_instr(new nop());
        code.push_instr(new twoRegs("move", reg, ZR));
        code.push_instr(new jl("b", end));
        code.push_instr(new nop());
        code.push_instr(new label(equal));
        code.push_instr(new regImm("li", reg, 1));
        code.push_instr(new label(end));
    }
};

class notEqualToExpr : public bin_Expr {
public:
    notEqualToExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        std::string notequal = code.get_Label();
        std::string end = code.get_Label();

        code.push_instr(new branch("bne", RR, RR + 1, notequal));
        code.push_instr(new nop());
        code.push_instr(new twoRegs("move", reg, ZR));
        code.push_instr(new jl("b", end));
        code.push_instr(new nop());
        code.push_instr(new label(notequal));
        code.push_instr(new regImm("li", reg, 1));
        code.push_instr(new label(end));
    }
};

class greaterThanExpr : public bin_Expr {
public:
    greaterThanExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("slt", reg, RR + 1, RR));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) > std::stol(right, nullptr, 0));
    }
};

class mod_Expr : public bin_Expr {
public:
    mod_Expr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) % std::stol(right, nullptr, 0));
    }

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();
        bin_Expr::codegen_helper(code, RR, RR + 1);
        code.push_instr(new twoRegs("div", RR, RR + 1));
        code.push_instr(new singleReg("mfhi", reg));
    }
};

class lessEqualExpr : public bin_Expr {
public:
    lessEqualExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();
        bin_Expr::codegen_helper(code, RR, RR + 1);
        code.push_instr(new threeRegs("slt", reg, RR + 1, RR));
        code.push_instr(new twoRegsImm("xori", reg, reg, 1));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) <= std::stol(right, nullptr, 0));
    }
};

class greaterEqualExpr : public bin_Expr {
public:
    greaterEqualExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();

        return std::to_string(std::stol(left, nullptr, 0) >= std::stol(right, nullptr, 0));
    }

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();
        bin_Expr::codegen_helper(code, RR, RR + 1);
        code.push_instr(new threeRegs("slt", reg, RR, RR + 1));
        code.push_instr(new twoRegsImm("xori", reg, reg, 1));
    }
};

class andExpr : public bin_Expr {
public:
    andExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();
        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("and", reg, RR, RR + 1));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) & std::stol(right, nullptr, 0));
    }
};

class orExpr : public bin_Expr {
public:
    orExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();
        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("or", reg, RR, RR + 1));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) | std::stol(right, nullptr, 0));
    }
};

class xorExpr : public bin_Expr {
public:
    xorExpr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();

        bin_Expr::codegen_helper(code, RR, RR + 1);

        code.push_instr(new threeRegs("xor", reg, RR, RR + 1));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) ^ std::stol(right, nullptr, 0));
    }
};

class logAnd : public bin_Expr {
public:
    logAnd(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();

        std::string zero = code.get_Label();
        std::string end = code.get_Label();

        code.set_DestReg(RR);
        bin_Expr::get_Left()->codegen(code);

        code.push_instr(new branch("beq", RR, ZR, zero));

        code.push_instr(new nop());


        code.set_DestReg(RR);

        bin_Expr::get_Right()->codegen(code);

        code.push_instr(new branch("beq", RR, ZR, zero));

        code.push_instr(new nop());

        code.push_instr(new li(reg, 1));

        code.push_instr(new jl("b", end));

        code.push_instr(new label(zero));

        code.push_instr(new twoRegs("move", reg, ZR));

        code.push_instr(new label(end));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) && std::stol(right, nullptr, 0));
    }
};

class logOr : public bin_Expr {
public:
    logOr(const expression* _left, const expression* _right) :
        bin_Expr(_left, _right) {}

    virtual void codegen(wrapper& code) const override
    {
        int reg = code.get_DestReg();

        std::string one = code.get_Label();

        std::string end = code.get_Label();

        code.set_DestReg(RR);
        bin_Expr::get_Left()->codegen(code);

        code.push_instr(new branch("bne", RR, ZR, one));

        code.push_instr(new nop());

        code.set_DestReg(RR);
        bin_Expr::get_Right()->codegen(code);

        code.push_instr(new branch("bne", RR, ZR, one));

        code.push_instr(new nop());

        code.push_instr(new twoRegs("move", reg, ZR));

        code.push_instr(new jl("b", end));

        code.push_instr(new label(one));

        code.push_instr(new li(reg, 1));
        
        code.push_instr(new label(end));
    }

    virtual std::string evaluate() const
    {
        std::string left = bin_Expr::get_Left()->evaluate();
        std::string right = bin_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) || std::stol(right, nullptr, 0));
    }
};

#endif