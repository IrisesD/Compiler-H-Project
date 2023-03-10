#ifndef SYSYF_DEADCODEELI_H
#define SYSYF_DEADCODEELI_H

#include "Pass.h"
#include "Module.h"
#include <queue>
#include <utility>

class DeadCodeEli : public Pass
{
public:
    DeadCodeEli(Module *module) : Pass(module) {}
    void execute() final;
    const std::string get_name() const override {return name;}
    bool is_critical(Instruction* inst);
    void mark();
    void sweep();
    void delete_bb();
    void Clean();
    bool Onepass();
    void ModifyPhi(BasicBlock* suc_bb, BasicBlock* bb, BasicBlock* pre_bb);
    bool Case3(BasicBlock* bb);
    bool Case4(BasicBlock* bb, BasicBlock* pre_bb);
private:
    Function *func_;
    std::set<Instruction*> mark_insts;
    const std::string name = "DeadCodeElimination";
};

#endif  // SYSYF_DEADCODEELI_H
