#include "var_type.hpp"
#include "wrapper.hpp"

variable::variable(const specifier* _spec) :
    spec(_spec) {}

variable::~variable() {}

const specifier* variable::get_type() const
{
    return spec;
}

localVariable::localVariable(wrapper& code, const specifier* _spec) :
    variable(_spec)
{
    fp = code.incr_FP(variable::get_type()->getSize(), frame_vars);
}

void localVariable::load(wrapper& code, uint8_t reg) const
{
    code.push_tmpOffset(new memoryOffset("lw", reg, fp, FP), frame_vars);
}

void localVariable::store(wrapper& code, uint8_t reg) const
{
    code.push_tmpOffset(new memoryOffset("sw", reg, fp, FP), frame_vars);
}

localVariableParam::localVariableParam(wrapper& code, const specifier* _spec, int pos) :
    variable(_spec),
    fp(pos)
{
    (void)code;
}

void localVariableParam::load(wrapper& code, uint8_t reg) const
{
    code.push_tmpOffset(new memoryOffset("lw", reg, fp, FP), frame_input_params);
}

void localVariableParam::store(wrapper& code, uint8_t reg) const
{
    code.push_tmpOffset(new memoryOffset("sw", reg, fp, FP), frame_input_params);
}

globalVariable::globalVariable(std::string _id, const specifier* _type) :
    variable(_type),
    id(_id) {}

void globalVariable::load(wrapper& code, uint8_t reg) const
{
    code.push_instr(new globalOffset("lw", reg, id));
}

void globalVariable::store(wrapper& code, uint8_t reg) const
{
    code.push_instr(new globalOffset("sw", reg, id));
}