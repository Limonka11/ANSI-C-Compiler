#ifndef AST_INITIALIZER_HPP
#define AST_INITIALIZER_HPP

#include "ast_expression.hpp"
#include "ast_binOp.hpp"
#include "ast_unaryOp.hpp"

class initial : public Node {
public:

    virtual const expression* get_expr() const = 0;

    virtual void codegen(wrapper& code) const
    {
        code.push_instr(new notWorking("initializer"));
    }
};

class initializerExpr : public initial {
private:
    const expression* val;
public:
    initializerExpr(const expression* _val) :
        val(_val) {}

    ~initializerExpr()
    {
        delete val;
    }

    virtual const expression* get_expr() const override
    {
        return val;
    }


    virtual void codegen(wrapper& code) const
    {
        code.set_DestReg(RR);
        val->codegen(code);
        code.set_DestReg(RR);
    }
};

#endif