#ifndef LLVM_FLATTENING_H
#define LLVM_FLATTENING_H
// LLVM libs
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instructions.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/Utils/Local.h"
//#include "llvm/Transforms/IPO/PassManagerBuilder.h"
// System libs
#include <vector>
#include <cstdlib>
#include <ctime>
namespace llvm {
class FlatteningPass : public PassInfoMixin<FlatteningPass> {
public:
  FlatteningPass() {}
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
  bool flatten(Function &F);
  static bool isRequired() { return true; }
};
FlatteningPass *createFlattening(bool flag);
};     // namespace llvm
#endif // LLVM_FLATTENING_H