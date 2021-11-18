#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include "ast_function.hpp"
#include "ast_int.hpp"

class param : public Node {
private:
    const specifier* specs;
    const declarator* dec;
public:
    param(const specifier* _specs, const declarator* _dec) :
        specs(_specs),
        dec(_dec) {}

    param(const declarator* _dec) :
        specs(new no_type()),
        dec(_dec) {}

    ~param()
    {
        delete specs;
        delete dec;
    }

    virtual void codegen(wrapper& code) const
    {
        int index = code.get_ParamIndex();
        
        if (index < 4) 
        {
            code.set_DestReg(index + 4);
            dec->localParam(code, specs, index*4, true);
        } else {
            dec->localParam(code, specs, index*4, false);
        }
    }
};

class paramList : public Node {
private:
    const Node* left;
    const Node* right;
public:
    paramList(const Node* _left, const Node* _right) :
        left(_left),
        right(_right) {}

    virtual void codegen(wrapper& code) const
    {
        left->codegen(code);
        code.incr_ParamIndex();
        right->codegen(code);
    }
};

#endif