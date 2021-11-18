#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

#include "expression.hpp"

class initializer : public Node {
public:
    virtual void print() const = 0;

    virtual const expression* get_expr() const = 0;
};

class initializerExpr : public initializer {
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

    virtual void print() const override
    {
        std::cout << " ";
        val->print();
        std::cout << " ";
    }
};

#endif