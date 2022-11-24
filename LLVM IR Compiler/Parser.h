#ifndef LLVM_IR_COMPILER_PARSER_H
#define LLVM_IR_COMPILER_PARSER_H

#include <memory>
#include <utility>

#include "ParseExpressions/Expression.h"
#include "ParseExpressions/ExpressionFile.h"
#include "Tokenizer.h"
#include "EnumRegistry.h"

namespace Parser {
    struct ParsingResult;

    using tokensArrayPointer = std::shared_ptr<Tokenizer::tokensArray>;
    using stringExtractResult = std::pair<std::string, bool>;
    using tokenPointer = std::shared_ptr<const Token::Token>;
    using expressionPointer = std::shared_ptr<const Expression::Expression>;

    class Parser {
        private:
            // FIXME Should I make this description more generic - remove mentions of checking if 'token' is
            //      a <T> type token?
            //      E.g. '<T> type token' -> '<T> type'

            // Returns whether or not the provided token is a <T> type token for the provided reserved string.
            // Returns false if '*token' is not a <T> type token, or the token's registryItem (reserved word, operator, etc.)
            // isn't the same as the provided RegistryItem; otherwise returns true.
            //
            // Note: Generically, this checks that '*token' can be dynamically cast to type <T>,
            //      and that (T)(*token).registryItem == reserved
            //      So, objects of type T must have a RegistryItem registryItem member.
            template<typename T>
            static bool checkReserved(tokenPointer token, EnumRegistry::RegistryItem reserved);

            static stringExtractResult attemptExtractString(tokenPointer token);
        public:
            ParsingResult parseSourceFile(tokensArrayPointer tokens, int startPos);
            ParsingResult parseDataLayout(tokensArrayPointer tokens, int startPos);
            std::shared_ptr<const Expression::ExpressionFile> parse(tokensArrayPointer tokens);
    };

    using newTokenPos = int;
    struct ParsingResult { // FIXME Merge this and TokenizeResult into one templated class.
        const expressionPointer expression;
        const newTokenPos newPos;
        const bool success;
        ParsingResult() : expression(), newPos(-1), success(false) {}
        ParsingResult(expressionPointer expressionArg, newTokenPos newPosArg)
                        : expression(expressionArg), newPos(newPosArg), success(true) {}
    };

    class ParsingException : public std::runtime_error {
        public:
            ParsingException(std::string msg) : runtime_error(msg.c_str()) {}
    };
}

#endif // LLVM_IR_COMPILER_PARSER_H