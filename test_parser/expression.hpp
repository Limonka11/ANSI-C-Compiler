#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "Node.hpp"
#include "type.hpp"

class expression : public Node {
public:
    virtual std::string evaluate() const
    {
        std::cerr << "Trying to evaluate an expression which is not constant";
        exit(1);
    }

    virtual bool is_list() const
    {
        return false;
    }

    virtual bool is_identifier() const
    {
        return false;
    }
};

class voidExpr : public expression
{
    virtual void print() const override {}
};

class identifier : public expression {
private:
    std::string id;
public:
    identifier(std::string* _id) :
        id(*_id)
    {
        delete _id;
    }

    virtual void print() const override
    {
        std::cout << " " << id << " ";
    }

    std::string get_id() const
    {
        return id;
    }

    virtual bool is_identifier() const
    {
        return true;
    }
};

class constant : public expression {
private:
    std::string val;
public:
    constant(std::string* _val) :
        val(*_val)
    {
        delete _val;
    }

        std::string get_val() const
    {
        return val;
    }

    virtual void print() const override
    {
        std::cout << " " << val << " ";
    }

    virtual std::string evaluate() const
    {
        return val;
    }
};

class int_constant : public constant {
public:
    int_constant(std::string* _val) :
        constant(_val) {}

    int int_value() const {
        return std::stol(constant::get_val(), nullptr, 0);
    }
};

class string_constant : public constant {
public:
    string_constant(std::string* _val) :
        constant(_val)
    {}
};

class binary_Expr : public expression {
private:
    const expression* left;
    const expression* right;
public:
    binary_Expr(const expression* _left, const expression* _right) :
        left(_left),
        right(_right) {}

    ~binary_Expr()
    {
        delete left;
        delete right;
    }

    const expression* get_Left() const
    {
        return left;
    }

    const expression* get_Right() const
    {
        return right;
    }
};

class addition_Expr : public binary_Expr {
public:
    addition_Expr(const expression* _left, const expression* _right) :
        binary_Expr(_left, _right) {}

    virtual void print() const override
    {
        binary_Expr::get_Left()->print();
        std::cout << "+";
        binary_Expr::get_Right()->print();
    }

    virtual std::string evaluate() const
    {
        std::string left = binary_Expr::get_Left()->evaluate();
        std::string right = binary_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) + std::stol(right, nullptr, 0));
    }
};

class subtraction_Expr : public binary_Expr {
public:
    subtraction_Expr(const expression* _left, const expression* _right) :
        binary_Expr(_left, _right) {}

    virtual void print() const override
    {
        binary_Expr::get_Left()->print();
        std::cout << "-";
        binary_Expr::get_Right()->print();
    }

    virtual std::string evaluate() const
    {
        std::string left = binary_Expr::get_Left()->evaluate();
        std::string right = binary_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) - std::stol(right, nullptr, 0));
    }
};

class multiplication_Expr : public binary_Expr {
public:
    multiplication_Expr(const expression* _left, const expression* _right) :
        binary_Expr(_left, _right) {}

    virtual void print() const override
    {
        binary_Expr::get_Left()->print();
        std::cout << "*";
        binary_Expr::get_Right()->print();
    }

    virtual std::string evaluate() const
    {
        std::string left = binary_Expr::get_Left()->evaluate();
        std::string right = binary_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) * std::stol(right, nullptr, 0));
    }
};

class equalToExpr : public binary_Expr {
public:
    equalToExpr(const expression* _left, const expression* _right) :
        binary_Expr(_left, _right) {}

    virtual void print() const override
    {
        binary_Expr::get_Left()->print();
        std::cout << " == ";
        binary_Expr::get_Right()->print();
    }
};

class lessThanExpr : public binary_Expr {
public:
    lessThanExpr(const expression* _left, const expression* _right) :
        binary_Expr(_left, _right) {}

    virtual void print() const override
    {
        binary_Expr::get_Left()->print();
        std::cout << " < ";
        binary_Expr::get_Right()->print();
    }

    virtual std::string evaluate() const
    {
        std::string left = binary_Expr::get_Left()->evaluate();
        std::string right = binary_Expr::get_Right()->evaluate();
        return std::to_string(std::stol(left, nullptr, 0) < std::stol(right, nullptr, 0));
    }
};

class assignmentExpr : public expression {
private:
    const identifier* left;
    const expression* right;
public:
    assignmentExpr(const expression* _left, const expression* _right) :
        right(_right)
    {
        if (_left->is_identifier()) {
            left = (identifier*)_left;
        } else {
            std::cerr << "Trying to assign a non-identifier " << std::endl;
            exit(1);
        }
    }

    ~assignmentExpr()
    {
        delete left;
        delete right;
    }

    const identifier* get_Left() const
    {
        return left;
    }

    const expression* get_Right() const
    {
        return right;
    }
};

class regularAssignment : public assignmentExpr {
public:
    regularAssignment(const expression* _left, const expression* _right) :
        assignmentExpr(_left, _right) {}

    virtual void print() const override
    {
        assignmentExpr::get_Left()->print();
        std::cout << " = ";
        assignmentExpr::get_Right()->print();
    }
};

class functionCall : public expression {
private:
    const identifier* idExpr;
public:
    functionCall(const expression* _idExpr)
    {
        if (_idExpr->is_identifier()) {
            idExpr = (identifier*)_idExpr;
        } else {
            std::cerr << "Function call to a non-identifier " << std::endl;
            exit(1);
        }
    }

    ~functionCall()
    {
        delete idExpr;
    }

    virtual void print() const override
    {
        std::cout << idExpr->get_id() << "()" << std::endl;
    }

    const identifier* get_idExpr() const
    {
        return idExpr;
    }
};

class functionCallParams : public functionCall {
private:
    const expression* args;
public:
    functionCallParams(const expression* _idExpr, const expression* _args) :
        functionCall(_idExpr),
        args(_args) {}

    ~functionCallParams()
    {
        delete args;
    }

    virtual void print() const override
    {
        std::cout << functionCall::get_idExpr()->get_id() << "(";
        args->print();
        std::cout << ")";
    }
};

class argumentExprList : public expression {
private:
    const expression* left;
    const expression* right;
public:
    argumentExprList(const expression* _left, const expression* _right) :
        left(_left),
        right(_right) {}

    ~argumentExprList()
    {
        delete left;
        delete right;
    }

    virtual bool is_list() const
    {
        return true;
    }

    virtual void print() const override
    {
        left->print();
        std::cout << ", ";
        right->print();
    }
};

#endif