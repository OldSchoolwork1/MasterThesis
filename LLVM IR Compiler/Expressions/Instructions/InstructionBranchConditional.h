#ifndef LLVM_IR_COMPILER_INSTRUCTIONTERMINATORYIELDSVOIDBranchConditional_H
#define LLVM_IR_COMPILER_INSTRUCTIONTERMINATORYIELDSVOIDBranchConditional_H

#include <string>
#include <memory>

#include "InstructionTerminatorYieldsVoid.h"
#include "../ExpressionLocalIdentifier.h"

namespace Instructions {
    class InstructionBranchConditional : public InstructionTerminatorYieldsVoid {
        public:
            const std::shared_ptr<const Expressions::ExpressionLocalIdentifier> condition;
            const std::shared_ptr<const Expressions::ExpressionLocalIdentifier> ifFalseLabel;
            const std::shared_ptr<const Expressions::ExpressionLocalIdentifier> ifTrueLabel;
            InstructionBranchConditional(std::shared_ptr<const Expressions::ExpressionLocalIdentifier> conditionArg,
                                         std::shared_ptr<const Expressions::ExpressionLocalIdentifier> ifFalseLabelArg,
                                         std::shared_ptr<const Expressions::ExpressionLocalIdentifier> ifTrueLabelArg)
                                             : condition(conditionArg), ifFalseLabel(ifFalseLabelArg),
                                               ifTrueLabel(ifTrueLabelArg) {}
            std::string getName() const override { return "InstructionBranchConditional"; }
    };
}

#endif // LLVM_IR_COMPILER_INSTRUCTIONTERMINATORYIELDSVOIDBranchConditional_H
