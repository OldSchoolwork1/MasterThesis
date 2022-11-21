#include "TokenParenthesis.h"

namespace Token {
    TokenizeResult TokenParenthesisConstructor::tokenize(BasicArray::BasicCharArray* fileData, int startPos) {
        bool success = false;
        bool left = true;
        char currChar = (*fileData)[startPos];
        switch (currChar) {
            case ')':
                left = false;
                success = true;
                break;
            case '(':
                success = true;
                break;
            default:
                break;
        }
        return success ? TokenizeResult(std::make_shared<TokenParenthesis>(left), startPos+1) : TokenizeResult();
    }
}