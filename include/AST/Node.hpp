#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <sstream>
#include <iostream>

class wrapper;

class Node {
public:
    Node() {}

    virtual ~Node() {}

    virtual void codegen(wrapper& code) const = 0;
};

class translationUnit : public Node {
private:
    const Node* left;
    const Node* right;
public:
    translationUnit(const Node* _left, const Node* _right) :
        left(_left),
        right(_right) {}

    ~translationUnit()
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

#endif