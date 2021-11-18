#ifndef wrapper_HPP
#define wrapper_HPP

#include <iostream>
#include <cstdint>
#include <stack>
#include <set>
#include <list>
#include <map>
#include "instructions.hpp"
#include "scope.hpp"

typedef std::list<mips_instr*>::iterator instr_pos;

enum frameType {
    frame_params = 0,
    frame_temps = 1,
    frame_vars = 2,
    frame_input_params = 3
};

class wrapper {
private:
    uint8_t destReg;

    std::list<mips_instr*> instructions;

    std::map<mips_instr*, frameType> temp_memOffsets;

    std::stack<int> paramIndex;

    std::set<uint8_t> savedRegs;

    std::stack<std::string> breaks;

    std::stack<std::string> continues;

    scope* currentScope;

    int framePointer[4];

    int maxFramePointer[4];

    int labelCount;

    int constLabelCount;

    std::string returnLabel;

    bool debugComments;
public:

    wrapper(bool debug = false);

    ~wrapper();

    void print(std::ostream &dst) const;

    instr_pos first_instr();

    instr_pos last_instr();

    instr_pos push_instr(mips_instr* in);

    instr_pos push_tmpOffset(mips_instr* in, frameType type);

    void insert_instr(instr_pos& pos, mips_instr* in);

    void set_DestReg(uint8_t reg);

    uint8_t get_DestReg() const;

    scope* get_CurrentScope() const;

    void create_Scope();

    void destroy_Scope();

    int incr_FP(int fp, frameType type);

    int decr_FP(int fp, frameType type);

    int get_FP(frameType type) const;

    void set_FP(int fp, frameType type);

    int get_MaxFP(frameType type) const;

    void reset_FP();

    void update_MemOffsets();

    void save_Reg(uint8_t reg);

    void reset_SavedRegs();

    void store_SavedRegs(instr_pos& pos);

    void load_SavedRegs(instr_pos& pos);

    int savedRegs_Size() const;

    int get_ParamIndex() const;

    void incr_ParamIndex();

    void reset_ParamIndex();

    void push_ParamIndex();

    void pop_ParamIndex();

    std::string get_Label();

    std::string get_ConstLabel();

    void set_ReturnLabel(std::string lab);

    std::string get_ReturnLabel() const;

    void push_Break(std::string label);

    std::string pop_Break();

    std::string get_TopBreak() const;

    void push_Continue(std::string label);

    std::string pop_Continue();

    std::string get_TopContinue() const;
};

#endif