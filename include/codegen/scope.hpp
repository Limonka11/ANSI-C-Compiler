#ifndef SCOPE_H
#define SCOPE_H

#include <map>

#include "var_type.hpp"

class scope {
public:
    scope(scope* _parent);

    virtual ~scope();

    scope* get_parent() const;

    virtual bool is_global() const;

    bool declare(std::string id, const variable* var);

    const variable* getVar(std::string id) const;

private:
    scope* parent;

    mutable std::map<std::string, const variable*> bindings;
};

class globalScope : public scope {
public:
    globalScope();

    virtual bool is_global() const override;
};

#endif