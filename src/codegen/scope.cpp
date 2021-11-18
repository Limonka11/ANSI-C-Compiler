#include "scope.hpp"

scope::scope(scope* _parent) :
    parent(_parent)
{
    std::map<std::string, const variable*>::iterator it;
    for (it = bindings.begin(); it != bindings.end(); ++it) 
    {
        delete it->second;
    }
}

scope::~scope() {}

scope* scope::get_parent() const
{
    return parent;
}

bool scope::is_global() const { return false; }

bool scope::declare(std::string id, const variable* var)
{
    if (bindings.find(id) != bindings.end())
    {
        return false;
    }

    bindings[id] = var;
    return true;
}

const variable* scope::getVar(std::string id) const
{
    if (bindings.find(id) == bindings.end())
    {
        if (parent == NULL)
        {
            // Global scope and binding not found
            return NULL;
        } else {
            return parent->getVar(id);
        }
    } else {
        return bindings[id];
    }
}

globalScope::globalScope() :
    scope(NULL) {}

bool globalScope::is_global() const { return true; }