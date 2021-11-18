#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include "Node.hpp"
#include "expression.hpp"

class statement : public Node {};

class compoundStat : public statement {
private:
    const Node* stats;
public:
    compoundStat(const Node* _stats) :
        stats(_stats) {}
    
    ~compoundStat()
    {
        delete stats;
    }
    
    virtual void print() const override
    {
        std::cout << "{" << std::endl;
        stats->print();
        std::cout << "}" << std::endl;
    }
};

class compoundStatDecs : public statement {
private:
    const Node* decs;
public:
    compoundStatDecs(const Node* _decs) :
        decs(_decs) {}

    ~compoundStatDecs()
    {
        delete decs;
    }

    virtual void print() const override
    {
        std::cout << "{ " << std::endl;
        decs->print();
        std::cout << "} " << std::endl;
    }
};

class compoundStatDecsStats : public statement {
private:
    const Node* decs;
    const Node* stats;
public:
    compoundStatDecsStats(const Node* _decs, const Node* _stats) :
        decs(_decs),
        stats(_stats) {}

    ~compoundStatDecsStats()
    {
        delete decs;
        delete stats;
    }

    virtual void print() const override
    {
        std::cout << "{ " << std::endl;
        decs->print();
        std::cout << std::endl;
        stats->print();
        std::cout << "} " << std::endl;
    }
};

class statList : public statement {
private:
    const Node* left;
    const Node* right;
public:
    statList(const Node* _left, const Node* _right) :
        left(_left),
        right(_right) {}

    ~statList()
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
        std::cout << std::endl;
    }
};

class emptyStat : public statement {

    virtual void print() const override
    {
        std::cout << "{}" << std::endl;
    }

};

class expressionStat : public statement {
private:
    const expression* expr;
public:
    expressionStat(const expression* _expr) :
        expr(_expr) {}

    ~expressionStat()
    {
        delete expr;
    }

    virtual void print() const override
    {
        expr->print();
        std::cout << ";" << std::endl;
    }
};

class selectionStat : public statement {
private:
    const expression* cond;
    const Node* stat;
public:
    selectionStat(const expression* _cond, const Node* _stat) :
        cond(_cond),
        stat(_stat) {}

    ~selectionStat()
    {
        delete cond;
        delete stat;
    }

    virtual void print() const override
    {
        std::cout << std::endl;
        std::cout << "if ( ";
        cond->print();
        std::cout << " ) ";
        stat->print();
    }

const expression* get_cond() const
    {
        return cond;
    }

    const Node* get_stat() const
    {
        return stat;
    }
};

class selectionStatElse : public selectionStat {
private:
    const Node* elseStat;
public:
    selectionStatElse(const expression* _cond, const Node* _stat, const Node* _elseStat) :
        selectionStat(_cond, _stat),
        elseStat(_elseStat) {}

    ~selectionStatElse()
    {
        delete elseStat;
    }

    virtual void print() const override
    {
        selectionStat::print();
        std::cout << std::endl << " else " << std::endl;
        elseStat->print();
    }
};

class whileStat : public statement {
private:
    const expression* cond;
    const Node* stat;
public:
    whileStat(const expression* _cond, const Node* _stat):
        cond(_cond),
        stat(_stat) {}
    
    ~whileStat()
    {
        delete cond;
        delete stat;
    }
    
    virtual void print() const override
    {
        std::cout << std::endl;
        std::cout << "while ( ";
        cond->print();
        std::cout << " ) ";
        stat->print();
    }
};

class returnStat : public statement {
private:
    const expression* expr;
public:
    returnStat(const expression* _expr):
        expr(_expr) {}

    ~returnStat()
    {
        delete expr;
    }

    virtual void print() const override
    {
        std::cout << std::endl;
        std::cout << "return ";
        expr->print();
        std::cout << ";" << std::endl;
    }
};

#endif