#ifndef TYPE_HPP
#define TYPE_HPP

#include "Node.hpp"

class declarationSpec : public Node {
public:

    virtual int get_Size() const = 0;
};

class declarationSpecList : public declarationSpec {
private:
    const declarationSpec* left;
    const declarationSpec* right;
public:
    declarationSpecList(const declarationSpec* _left, const declarationSpec* _right) :
        left(_left),
        right(_right) {}

    ~declarationSpecList()
    {
        delete left;
        delete right;
    }

    virtual void print() const override
    {
        left->print();
        std::cout << " ";
        right->print();
        std::cout << " ";
    }

    virtual int get_Size() const
    {
        return left->get_Size() + right->get_Size();
    }
};

class type : public declarationSpec {
public:
    virtual void print() const = 0;
};

class no_type : public type {
public:
    virtual int get_Size() const override
    {
        return 4;
    }

    virtual void print() const override {}
};

class int_type: public type {
public:
    virtual int get_Size() const override
    {
        return 4;
    }

    virtual void print() const override
    {
        std::cout << "int";
    }
};

class string_type: public type {
public:
    virtual void print() const override
    {
        std::cout << "string ";
    }
};

#endif