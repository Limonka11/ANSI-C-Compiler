#include "ast_int.hpp"
#include "wrapper.hpp"

void specifier::codegen(wrapper& code) const
{
    code.push_instr(new notWorking("declarationSpecifier"));
}

specList::~specList()
{
    delete left;
    delete right;
}


int specList::getSize() const 
{
    int leftSize = left->getSize();
    int rightSize = right->getSize();

    return leftSize > rightSize ? leftSize : rightSize;
}

void specList::codegen(wrapper& code) const
{
    code.push_instr(new notWorking("declarationSpecifierList"));
}

int int_t::getSize() const
{
    return 4;
}

int no_type::getSize() const
{
    return 4;
}

int void_t::getSize() const
{
    return 0;
}

/*
int float_type::getSize() const
{
    return 4;
}
*/
int array_t::getSize() const
{
    return size * type->getSize();
}