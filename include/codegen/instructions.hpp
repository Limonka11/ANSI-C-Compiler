#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <string>
#include <cstdint>
#include <iostream>

extern const int ZR;
extern const int RR;
extern const int FRR;
extern const int SP;
extern const int FP;
extern const int LR;
extern const int NUM_PARAM_REGS;
extern const int PARAM_REGS[4];
extern const int TEMP_REGS[8];

class mips_instr {
public:
    virtual void print(std::ostream &dst) const = 0;
    virtual ~mips_instr() {}
    virtual bool isDebug() const
    {
        return false;
    }

    virtual void incrementOffset(int baseOffset)
    {
        (void) baseOffset;
        exit(1);
    }
};

class emptyInstr : public mips_instr {
    //virtual void print() const override 
    //{
     //   (void)dst;
    //}
};

class dir : public mips_instr {
private:
    std::string name;
    std::string str;
public:
    dir(std::string _name, std::string _str) :
        name(_name),
        str(_str) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t." <<name<< "\t" <<str<<std::endl;
    }
};

class nop : public mips_instr {
public:
    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<"nop"<<std::endl;
    }
};

class label : public mips_instr {
private:
    std::string name;
public:
    label(std::string _name) :
        name(_name) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< name << ":" << std::endl;
    }
};

class operation : public mips_instr {
private:
    std::string op;
public:
    operation(std::string _op) :
        op(_op) {}

    std::string getOp() const
    {
        return op;
    }
};

class jr : public operation {
private:
    uint8_t reg;
public:
    jr(std::string _op, uint8_t _reg) :
        operation(_op),
        reg(_reg) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)reg<<std::endl;
    }
};

class jl : public operation {
private:
    std::string label;
public:
    jl(std::string _op, std::string _label) :
        operation(_op),
        label(_label) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t" <<label<<std::endl;
    }
};

class branch : public operation {
private:
    uint8_t dest;
    uint8_t source;
    std::string name;
public:
    branch(std::string _op, uint8_t _dest, uint8_t _source, std::string _name) :
        operation(_op),
        dest(_dest),
        source(_source),
        name(_name) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", $" <<(int)source<< ", " <<name<<std::endl;
    }
};

class li : public operation {
private:
    uint8_t dest;
    int imm;
public:
    li(uint8_t _dest, int _imm) :
        operation("li"),
        dest(_dest),
        imm(_imm) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", " <<imm<<std::endl;
    }
};

class li_S : public operation {
private:
    uint8_t dest;
    float imm;
public:
    li_S(uint8_t _dest, float _imm) :
        operation("li.s"),
        dest(_dest),
        imm(_imm) {}

    virtual void print(std::ostream &dst) const override
    {
        std::string tmp = std::to_string(imm);
        dst<< "\t" <<operation::getOp()<< "\t$f" <<(int)dest<< ", " << tmp <<std::endl;
    }
};

class regImm : public operation {
private:
    uint8_t dest;
    int immediate;
public:
    regImm(std::string _op, uint8_t _dest, int _immediate) :
        operation(_op),
        dest(_dest),
        immediate(_immediate) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", " <<immediate<< std::endl;
    }
};

class singleReg : public operation {
private:
    uint8_t dest;
public:
    singleReg(std::string _op, uint8_t _dest) :
        operation(_op),
        dest(_dest) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<<std::endl;
    }
};

class twoRegs : public operation {
private:
    uint8_t dest;
    uint8_t source;
public:
    twoRegs(std::string _op, uint8_t _dest, uint8_t _source) :
        operation(_op),
        dest(_dest),
        source(_source) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", $" <<(int)source<<std::endl;
    }
};

class twoRegsFloat : public operation {
private:
    uint8_t dest;
    uint8_t source;
public:
    twoRegsFloat(std::string _op, uint8_t _dest, uint8_t _source) :
        operation(_op),
        dest(_dest),
        source(_source) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$f" <<(int)dest<< ", $f" <<(int)source<<std::endl;
    }
};

class twoRegsImm : public operation {
private:
    uint8_t dest;
    uint8_t source;
    int imm;
public:
    twoRegsImm(std::string _op, uint8_t _dest, uint8_t _source, int _imm) :
        operation(_op),
        dest(_dest),
        source(_source),
        imm(_imm) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", $" <<(int)source<< ", " <<imm<<std::endl;
    }

    virtual void incrementOffset(int baseOffset) override
    {
        imm += baseOffset;
    }
};

class threeRegs : public operation {
private:
    uint8_t dest;
    uint8_t reg1;
    uint8_t reg2;
public:
    threeRegs(std::string _op, uint8_t _dest, uint8_t _reg1, uint8_t _reg2) :
        operation(_op),
        dest(_dest),
        reg1(_reg1),
        reg2(_reg2) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", $" <<(int)reg1<< ", $" <<(int)reg2<<std::endl;
    }
};

class threeRegsFloat : public operation {
private:
    uint8_t dest;
    uint8_t reg1;
    uint8_t reg2;
public:
    threeRegsFloat(std::string _op, uint8_t _dest, uint8_t _reg1, uint8_t _reg2) :
        operation(_op),
        dest(_dest),
        reg1(_reg1),
        reg2(_reg2) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$f" <<(int)dest<< ", $f" <<(int)reg1<< ", $f" <<(int)reg2<<std::endl;
    }
};

class globalOffset : public operation {
private:
    uint8_t dest;
    std::string offset;
public:
    globalOffset(std::string _op, uint8_t _dest, std::string _offset) :
        operation(_op),
        dest(_dest),
        offset(_offset) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", " <<offset<<std::endl;
    }
};

class notWorking : public operation {
public:
    notWorking(std::string _op) :
        operation(_op) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "# Not Working : " <<operation::getOp()<<std::endl;
        exit(1);
    }
};

class memoryOffset : public operation {
private:
    uint8_t dest;
    int32_t offset;
    uint8_t source;
public:
    memoryOffset(std::string _op, uint8_t _dest, int32_t _offset, uint8_t _source) :
        operation(_op),
        dest(_dest),
        offset(_offset),
        source(_source) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$" <<(int)dest<< ", " <<(int)offset<< "($" <<(int)source<< ")" <<std::endl;
    }

    virtual void incrementOffset(int baseOffset) override
    {
        offset += baseOffset;
    }
};

class memoryOffsetFloat : public operation {
private:
    uint8_t dest;
    int32_t offset;
    uint8_t source;
public:
    memoryOffsetFloat(std::string _op, uint8_t _dest, int32_t _offset, uint8_t _source) :
        operation(_op),
        dest(_dest),
        offset(_offset),
        source(_source) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "\t" <<operation::getOp()<< "\t$f" <<(int)dest<< ", " <<(int)offset<< "($" <<(int)source<< ")" <<std::endl;
    }

    virtual void incrementOffset(int baseOffset) override
    {
        offset += baseOffset;
    }
};

class debugComment : public operation {
public:
    debugComment(std::string _op) :
        operation(_op) {}

    virtual void print(std::ostream &dst) const override
    {
        dst<< "# " <<operation::getOp()<<std::endl;
    }

    virtual bool isDebug() const override
    {
        return true;
    }
};

#endif