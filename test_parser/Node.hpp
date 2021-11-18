#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <iostream>

class Node {
public:
    Node() {}

    virtual ~Node() {}

    virtual void print() const {}
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

    virtual void print() const override
    {
        std::cout << std::endl;
        left->print();
        std::cout << std::endl;
        right->print();

    }
};

#endif