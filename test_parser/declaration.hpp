#ifndef DECLARATION_HPP
#define DECLARATION_HPP

#include "Node.hpp"
#include "statement.hpp"
#include "initializer.hpp"
#include "type.hpp"

class declarator : public Node {
public:
    virtual void print() const = 0;
    virtual std::string get_id() const
    {
        return "";
    }

    virtual bool is_variable() const
    {
        return false;
    }
};

class idDeclarator : public declarator {
private:
    std::string id;
public:
    idDeclarator(std::string _id) :
        id(_id) {}

    virtual std::string get_id() const override
    {
        return id;
    }
};

//we need it to inherit from Node becasuse we may need more than two declarators
class declaratorList : public declarator {
private:
    const declarator* left;
    const declarator* right;
public:
    declaratorList(const declarator* _left, const declarator* _right) :
        left(_left),
        right(_right) {}

    ~declaratorList()
    {
        delete left;
        delete right;
    }

    virtual void print() const override {
        left->print();
        std::cout << "," << std::endl;
        right->print();
    }
};

//name of var
class varDeclarator : public idDeclarator {
public:
    varDeclarator(std::string* _id) :
        idDeclarator(*_id) {
            delete _id;
        }

    virtual void print() const override
    {
        std::cout << " " << idDeclarator::get_id() << " ";
    }

    virtual bool is_variable() const override
    {
        return true;
    }
};

//int x=5
class initDeclarator : public declarator {
private:
    const declarator* decl;
    const initializer* val;
public:
    initDeclarator(const declarator* _decl, const initializer* _val) :
        decl(_decl),
        val(_val) {}

    ~initDeclarator()
    {
        delete decl;
        delete val;
    }

    virtual std::string get_id() const override
    {
        return decl->get_id();
    }

    virtual void print() const override
    {
        decl->print();
        std::cout << " = ";
        val->print();
    }
};

class voidDeclaration : public Node {
public:
    virtual void print() const override {}
};

//int x
class declaration : public Node {
private:
    const declarationSpec* specs;
    const declarator* decs;
public:
    declaration(const declarationSpec* _specs, const declarator* _decs) :
        specs(_specs),
        decs(_decs) {}

    ~declaration()
    {
        delete specs;
        delete decs;
    }

    virtual void print() const override
    {
        specs->print();
        std::cout << " ";
        decs->print();
        std::cout << ";" << std::endl;
    }
};

class declarationList : public Node {
private:
    const Node* left;
    const Node* right;
public:
    declarationList(const Node* _left, const Node* _right) :
        left(_left),
        right(_right) {}

    ~declarationList()
    {
        delete left;
        delete right;
    }

    virtual void print() const override
    {
        left->print();
        std::cout << std::endl;
        right->print();
    }
};

//foo()
class functionDeclarator : public declarator {
private:
    const declarator* dec;
public:
    functionDeclarator(const declarator* _dec) :
        dec(_dec) {}

    ~functionDeclarator()
    {
        delete dec;
    }

    virtual std::string get_id() const override
    {
        return dec->get_id();
    }

    virtual void print() const override 
    {
        std::cout << dec->get_id() << " () ";
    }
};

class functionDeclaratorParams : public functionDeclarator {
private:
    const Node* params;
public:
    functionDeclaratorParams(const declarator* _dec, const Node* _params):
        functionDeclarator(_dec),
        params(_params) {}

    ~functionDeclaratorParams()
    {
        delete params;
    }

    virtual void print() const override
    {
        std::cout << functionDeclarator::get_id() << " (";
        params->print();
        std::cout << ") ";
    }
};

//int foo()
class functionDeclaration : public Node {
private:
    const Node* specs;
    const declarator* dec;
public:
    functionDeclaration(const Node* _specs, const declarator* _dec) :
        specs(_specs),
        dec(_dec) {}

    std::string get_id() const
    {
        return dec->get_id();
    }

    virtual void print() const override 
    {
        specs->print();
        std::cout << " ";
        dec->print();
    }
};


class functionDef : public Node {
private:
    const Node* specs;
    const functionDeclarator* dec;
    const Node* stat;
public:
    functionDef(const Node* _specs, const declarator* _dec, const Node* _stat) :
        specs(_specs),
        dec((functionDeclarator*)_dec),
        stat(_stat) {}

    ~functionDef()
    {
        delete specs;
        delete dec;
        delete stat;
    }

    virtual void print() const override {
        printSpecsDec();
        stat->print();
    }

    void printSpecsDec() const
    {
        specs->print();
        std::cout << " ";
        dec->print();
    }

    const Node* get_Stat() const
    {
        return stat;
    }
};

class functionDefDeclList : public functionDef {
private:
    const Node* decList;
public:
    functionDefDeclList(const Node* _specs, const declarator* _dec, const Node* _decList, const Node* _stat) :
        functionDef(_specs, _dec, _stat),
        decList(_decList) {}

    ~functionDefDeclList()
    {
        delete decList;
    }

    virtual void print() const override {
        functionDef::printSpecsDec();
        std::cout << std::endl;
        decList->print();
        functionDef::get_Stat()->print();
    }
};

#endif