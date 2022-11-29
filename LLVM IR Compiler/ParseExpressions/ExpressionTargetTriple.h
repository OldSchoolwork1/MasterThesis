#ifndef LLVM_IR_COMPILER_EXPRESSIONTARGETTRIPLE_H
#define LLVM_IR_COMPILER_EXPRESSIONTARGETTRIPLE_H

#include <string>

#include "Expression.h"

namespace Expression {
    class ExpressionTargetTriple : public Expression {
        public:
            // FIXME: Should it store the triple components?
            const std::string triple;
            ExpressionTargetTriple(std::string tripleArg) : triple(tripleArg) {}
            std::string getName() { return "ExpressionTargetTriple("+triple+")"; }
    };
}

#endif // LLVM_IR_COMPILER_EXPRESSIONTARGETTRIPLE_H
