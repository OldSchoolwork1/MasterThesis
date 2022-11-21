#ifndef LLVM_IR_COMPILER_TOKENCOMMENT_H
#define LLVM_IR_COMPILER_TOKENCOMMENT_H

#include <string>

#include "Token.h"

namespace Token {
    class TokenComment : public Token::Token {
        public:
            std::string comment;
            TokenComment(std::string commentArg) : comment(commentArg) {}
            std::string getName() const {return "TokenComment("+comment+")"; }
    };

    class TokenCommentConstructor : public TokenConstructor {
        public:
            TokenizeResult tokenize(BasicArray::BasicCharArray* fileData, int startPos);
    };
}

#endif // LLVM_IR_COMPILER_TOKENCOMMENT_H