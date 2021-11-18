#ifndef AST_UNARYOP_HPP
#define AST_UNARYOP_HPP

#include "ast_expression.hpp"

class unary_Expr : public identifier {
private:
    const expression* expr;
public:
    unary_Expr(const expression* _expr) :
        identifier(new std::string("")),
        expr(_expr) {}

    ~unary_Expr()
    {
        delete expr;
    }

    const expression* get_Expr() const
    {
        return expr;
    }
};

class bitNot : public unary_Expr {
public:
    bitNot(const expression* _expr) :
        unary_Expr(_expr) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();
        
        unary_Expr::get_Expr()->codegen(code);

        code.push_instr(new twoRegs("not", reg, reg));
    }

    virtual std::string evaluate() const
    {
        return std::to_string(~std::stol(unary_Expr::get_Expr()->evaluate(), nullptr, 0));
    }
};

class scalarNot : public unary_Expr {
public:
    scalarNot(const expression* _expr) :
        unary_Expr(_expr) {}

    virtual void codegen(wrapper& code) const override
    {

        int reg = code.get_DestReg();
        
        unary_Expr::get_Expr()->codegen(code);

        code.push_instr(new threeRegs("sltiu", reg, reg, 1));
    }

    virtual std::string evaluate() const
    {
        return std::to_string(!std::stol(unary_Expr::get_Expr()->evaluate(), nullptr, 0));
    }
};

class negation : public unary_Expr {
public:
    negation(const expression* _expr) :
        unary_Expr(_expr) {}

    virtual void codegen(wrapper& code) const override
    {
        int tmp = code.get_DestReg();
        unary_Expr::get_Expr()->codegen(code);
        code.push_instr(new threeRegs("sub", tmp, ZR, tmp));
    }

    virtual std::string evaluate() const
    {
        return std::to_string(-std::stol(unary_Expr::get_Expr()->evaluate(), nullptr, 0));
    }
};

class positive : public unary_Expr {
public:
    positive(const expression* _expr) :
        unary_Expr(_expr) {}

    virtual void codegen(wrapper& code) const override
    {
        unary_Expr::get_Expr()->codegen(code);
    }

    virtual std::string evaluate() const
    {
        return unary_Expr::get_Expr()->evaluate();
    }
};

#endif