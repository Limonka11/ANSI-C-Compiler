#ifndef VARIABLES_H
#define VARIABLES_H

#include <cstdint>
#include <string>

#include "instructions.hpp"
#include "ast_int.hpp"

class wrapper;

class variable {
private:
    const specifier* spec;
public:
    variable(const specifier* _spec);

    virtual ~variable();

    virtual void load(wrapper& code, uint8_t reg) const = 0;

    virtual void store(wrapper& code, uint8_t reg) const = 0;

    const specifier* get_type() const;
};

class localVariable : public variable {
private:
    int fp;
public:
    localVariable(wrapper& code, const specifier* spec);

    virtual void load(wrapper& code, uint8_t reg) const override;

    virtual void store(wrapper& code, uint8_t reg) const override;
};

class localVariableParam : public variable {
private:
    int fp;
public:
    localVariableParam(wrapper& code, const specifier* spec, int pos);

    virtual void load(wrapper& code, uint8_t reg) const override;

    virtual void store(wrapper& code, uint8_t reg) const override;
};

class globalVariable : public variable {
private:
    std::string id;
public:
    globalVariable(std::string _id, const specifier* spec);

    virtual void load(wrapper& code, uint8_t reg) const override;

    virtual void store(wrapper& code, uint8_t reg) const override;
};

#endif