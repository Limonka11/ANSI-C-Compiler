#ifndef AST_FUNCTION_HPP
#define AST_FUNCTION_HPP

#include "ast_declare.hpp"

//foo()
class funcDecl : public declarator {
private:
    const declarator* dec;
public:
    funcDecl(const declarator* _dec) :
        dec(_dec) {}

    ~funcDecl()
    {
        delete dec;
    }

    virtual std::string get_id() const override
    {
        return dec->get_id();
    }

    virtual void codegen(wrapper& code) const override
    {
        (void)code;
    }

    virtual void global(wrapper& code, const specifier* type) const
    {
        (void)code;
        (void)type;
    }
};

class funcDeclParam : public funcDecl {
private:
    const Node* params;
public:
    funcDeclParam(const declarator* _dec, const Node* _params):
        funcDecl(_dec),
        params(_params) {}

    ~funcDeclParam()
    {
        delete params;
    }

    virtual void codegen(wrapper& code) const override
    {
        code.reset_ParamIndex();
        params->codegen(code);
    }
};

//int foo()
class funcDeclaration : public Node {
private:
    const Node* specs;
    const declarator* dec;
public:
    funcDeclaration(const Node* _specs, const declarator* _dec) :
        specs(_specs),
        dec(_dec) {}

    std::string get_id() const
    {
        return dec->get_id();
    }

    virtual void codegen(wrapper& code) const { (void)code; }
};


class funcDef : public Node {
private:
    const Node* specs;
    const funcDecl* dec;
    const Node* stat;
public:
    funcDef(const Node* _specs, const declarator* _dec, const Node* _stat) :
        specs(_specs),
        dec((funcDecl*)_dec),
        stat(_stat) {}

    ~funcDef()
    {
        delete specs;
        delete dec;
        delete stat;
    }

    const Node* getStat() const
    {
        return stat;
    }

    virtual void codegen(wrapper& code) const
    {
        //function preamble
        code.set_ReturnLabel(code.get_Label());

        code.push_instr(new dir("text", ""));

        code.push_instr(new dir("globl", dec->get_id()));

        code.save_Reg(FP);

        instr_pos func_pos = code.push_instr(new label(dec->get_id()));

        code.create_Scope();

        dec->codegen(code);

        code.set_DestReg(RR);

        stat->codegen(code);

        code.destroy_Scope();

        // Get the frame pointer at the end of the function
        int fp = code.get_MaxFP(frame_params) + code.get_MaxFP(frame_temps) + code.get_MaxFP(frame_vars) + code.savedRegs_Size();

        // Do the stack management at the beginning of the function
        func_pos++;
        
        code.insert_instr(func_pos, new twoRegsImm("addiu", SP, SP, -fp));

        code.store_SavedRegs(func_pos);

        code.insert_instr(func_pos, new twoRegs("move", FP, SP));

        code.push_instr(new label(code.get_ReturnLabel()));
        
        // Stack management at the end of the function
        code.push_instr(new twoRegs("move", SP, FP));

        // Load from the stack any registers which were changed in the function
        instr_pos end = code.last_instr();
        code.load_SavedRegs(end);

        code.push_instr(new twoRegsImm("addiu", SP, SP, fp));

        // Return from function
        code.push_instr(new jr("jr", LR));
        code.push_instr(new nop());

        code.push_instr(new debugComment("--- END FUNCTION DEFINITION ---"));

        code.update_MemOffsets();
        code.reset_SavedRegs();
        code.reset_FP();
    }
};

class funcDefDeclList : public funcDef {
private:
    const Node* decList;
public:
    funcDefDeclList(const Node* _specs, const declarator* _dec, const Node* _decList, const Node* _stat) :
        funcDef(_specs, _dec, _stat),
        decList(_decList) {}

    ~funcDefDeclList()
    {
        delete decList;
    }
};


#endif