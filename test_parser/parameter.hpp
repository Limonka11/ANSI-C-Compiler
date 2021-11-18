#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include "declaration.hpp"
#include "type.hpp"

class paramDeclaration : public Node {
private:
    const declarationSpec* specs;
    const declarator* dec;
public:
    paramDeclaration(const declarationSpec* _specs, const declarator* _dec) :
        specs(_specs),
        dec(_dec) {}

    paramDeclaration(const declarator* _dec) :
        specs(new no_type()),
        dec(_dec) {}

    ~paramDeclaration()
    {
        delete specs;
        delete dec;
    }

    virtual void print() const override 
    {
        std::cout << " ";
        specs->print();
        std::cout << " ";
        dec->print();
        std::cout << " ";
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

    virtual void print() const override
    {
        left->print();
        std::cout << ",";
        right->print();
    }
};

#endif