#include "wrapper.hpp"

wrapper::wrapper(bool debug) :
    debugComments(debug)
{
    reset_FP();
    destReg = RR;

    labelCount = 0;

    currentScope = new globalScope();

    paramIndex.push(0);
}

wrapper::~wrapper()
{
    instr_pos it;
    for (it = instructions.begin(); it != instructions.end(); it++)
    {
        delete *it;
    }

    delete currentScope;
}

void wrapper::print(std::ostream &dst) const
{
    std::list<mips_instr*>::const_iterator it;
    for (it = instructions.begin(); it != instructions.end(); it++)
    {
        if (!(!debugComments && (*it)->isDebug())) {
            (*it)->print(dst);
        }
    }
}

instr_pos wrapper::first_instr()
{
    return instructions.begin();
}

instr_pos wrapper::last_instr()
{
    return instructions.end();
}

instr_pos wrapper::push_instr(mips_instr* in)
{
    instructions.push_back(in);
    instr_pos it = instructions.end();
    return --it;
}

instr_pos wrapper::push_tmpOffset(mips_instr* in, frameType type)
{
    temp_memOffsets[in] = type;
    return push_instr(in);
}

void wrapper::insert_instr(instr_pos& pos, mips_instr* in)
{
    instructions.insert(pos, in);
}

void wrapper::set_DestReg(uint8_t reg)
{
    destReg = reg;
}

uint8_t wrapper::get_DestReg() const
{
    return destReg;
}

scope* wrapper::get_CurrentScope() const
{
    return currentScope;
}

void wrapper::create_Scope()
{
    currentScope = new scope(currentScope);
}

void wrapper::destroy_Scope()
{
    scope* parent = currentScope->get_parent();
    delete currentScope;
    currentScope = parent;
}

int wrapper::incr_FP(int fp, frameType type)
{
    if (type == frame_params)
    {
        if (maxFramePointer[frame_params] < 16)
        {
            maxFramePointer[frame_params] = 16;
        }
    }

    int oldFramePointer = framePointer[type];
    framePointer[type] += fp;

    if (framePointer[type] > maxFramePointer[type])
    {
        maxFramePointer[type] = framePointer[type];
    }

    return oldFramePointer;
}

int wrapper::decr_FP(int fp, frameType type)
{
    int oldFramePointer = framePointer[type];
    framePointer[type] -= fp;
    return oldFramePointer;
}

int wrapper::get_FP(frameType type) const
{
    return framePointer[type];
}

void wrapper::set_FP(int fp, frameType type)
{
    framePointer[type] = fp;
    incr_FP(4, type);
}

int wrapper::get_MaxFP(frameType type) const
{
    return maxFramePointer[type];
}

void wrapper::reset_FP()
{
    for (int i = frame_params; i <= frame_input_params; i++)
    {
        framePointer[i] = 0;
        maxFramePointer[i] = 0;
    }
}

void wrapper::update_MemOffsets()
{
    std::map<mips_instr*, frameType>::iterator it;
    for (it = temp_memOffsets.begin(); it != temp_memOffsets.end(); it++)
    {
        for (int i = frame_params; i <= frame_input_params; i++)
        {
            if (it->second > i)
            {
                it->first->incrementOffset(maxFramePointer[i]);
            }
        }
        if (it->second == frame_input_params)
        {
            it->first->incrementOffset(savedRegs_Size());
        }
    }

    temp_memOffsets.clear();
}

void wrapper::save_Reg(uint8_t reg)
{
    savedRegs.insert(reg);
}

void wrapper::reset_SavedRegs()
{
    savedRegs.clear();
}

void wrapper::store_SavedRegs(instr_pos& pos)
{
    int fp = maxFramePointer[frame_params] + maxFramePointer[frame_temps] + maxFramePointer[frame_vars];
    std::set<uint8_t>::iterator it;
    for (it = savedRegs.begin(); it != savedRegs.end(); it++)
    {
        insert_instr(pos, new memoryOffset("sw", *it, fp, SP));
        fp += 4;
    }
}

void wrapper::load_SavedRegs(instr_pos& pos)
{
    int fp = maxFramePointer[frame_params] + maxFramePointer[frame_temps] + maxFramePointer[frame_vars];
    std::set<uint8_t>::iterator it;
    for (it = savedRegs.begin(); it != savedRegs.end(); it++)
    {
        insert_instr(pos, new memoryOffset("lw", *it, fp, SP));
        fp += 4;
    }
}

int wrapper::savedRegs_Size() const
{
    return savedRegs.size() * 4;
}

int wrapper::get_ParamIndex() const
{
    return paramIndex.top();
}

void wrapper::incr_ParamIndex()
{
    paramIndex.top()++;
}

void wrapper::reset_ParamIndex()
{
    paramIndex.top() = 0;
}

void wrapper::push_ParamIndex()
{
    paramIndex.push(0);
}

void wrapper::pop_ParamIndex()
{
    paramIndex.pop();
}

std::string wrapper::get_Label()
{
    return std::string("$L") + std::to_string(++labelCount);
}

std::string wrapper::get_ConstLabel()
{
    return std::string("$LC") + std::to_string(++constLabelCount);
}

void wrapper::set_ReturnLabel(std::string lab)
{
    returnLabel = lab;
}

std::string wrapper::get_ReturnLabel() const
{
    return returnLabel;
}

void wrapper::push_Break(std::string label)
{
    breaks.push(label);
}

std::string wrapper::pop_Break()
{
    if (breaks.empty())
    {
        exit(1);
    }
    std::string label = breaks.top();
    breaks.pop();
    return label;
}

std::string wrapper::get_TopBreak() const
{
    return breaks.top();
}

void wrapper::push_Continue(std::string label)
{
    continues.push(label);
}

std::string wrapper::pop_Continue()
{
    if (continues.empty())
    {
        exit(1);
    }
    std::string label = continues.top();
    continues.pop();
    return label;
}

std::string wrapper::get_TopContinue() const
{
    return continues.top();
}