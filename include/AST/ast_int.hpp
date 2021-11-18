#ifndef AST_INT_HPP
#define AST_INT_HPP

#include "Node.hpp"

class specifier : public Node {
public:

    virtual int getSize() const = 0;

    virtual bool is_int() const
    {
        return false;
    }

    /*
    virtual bool is_float() const
    {
        return false;
    }
    */

    virtual void codegen(wrapper& code) const;
};

class specList : public specifier {
private:
    const specifier* left;
    const specifier* right;
public:
    specList(const specifier* _left, const specifier* _right) :
        left(_left),
        right(_right) {}

    ~specList();

    virtual int getSize() const override;

    virtual void codegen(wrapper& code) const;

    virtual bool is_int() const
    {
        return left->is_int() || right->is_int();
    }

    /*
    virtual bool is_float() const
    {
        return left->is_float() || right->is_float();
    }
    */
};

class type : public specifier {};

class no_type : public type {
public:
    virtual int getSize() const override;
};

class int_t: public type {
public:
    virtual int getSize() const override;

    virtual bool is_int() const override { return true; }
};

class void_t : public type {
public:
    virtual int getSize() const override;
};

/*
class float_type : public type {
public:
    virtual int getSize() const override;

    virtual bool is_float() const override { return true; }
};
*/

class array_t : public type {
private:
    int size;
    const specifier* type;
public:
    array_t(int _size, const specifier* _type) :
        size(_size),
        type(_type) {}

    virtual int getSize() const override;
};

#endif