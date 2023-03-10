//
// Created by 吴骏 on 2023/1/1.
//

#ifndef SYSYF_CONSTPROPAGATION_H
#define SYSYF_CONSTPROPAGATION_H
#include "Pass.h"
#include "Constant.h"
#include "Instruction.h"
#include "Module.h"
#include "Value.h"
#include "IRStmtBuilder.h"

// 用来判断value是否为ConstantFloat/ConstantInt
ConstantInt *cast_to_const_int(Value *value);
ConstantFloat *cast_to_const_float(Value *value);

class ConstFolder
{
public:
    ConstFolder(Module *module) : module_(module) {}
   
    ConstantInt *compute(Instruction::OpID op, ConstantInt *value1, ConstantInt *value2);
    ConstantFloat *compute_f(Instruction::OpID op, ConstantFloat *value1, ConstantFloat *value2);
    ConstantInt *GetCmpValue(CmpInst::CmpOp op, int const_value1,int const_value2);
    ConstantFloat *GetFCmpValue(FCmpInst::CmpOp op, float const_value1, float const_value2);
    
private:
    Module *module_;
};

class ConstPropagation : public Pass
{
private:
    const std::string name = "ConstPropagation";

public:
    ConstPropagation(Module *module) : Pass(module) {}
    void execute() final;
    const std::string get_name() const override {return name;}
};

#endif  // SYSYF_CONSTPROPAGATION_H
