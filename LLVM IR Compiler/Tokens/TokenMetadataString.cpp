#include "TokenMetadataString.h"

#include "HelperFunctionsTokens.h"

namespace Token {
    TokenizeResult TokenMetadataStringConstructor::tokenize(BasicArray::BasicCharArray* fileData, int startPos) {
        TokenLib::stringParseResult result = (fileData->positionInBounds(startPos) && (*fileData)[startPos] == '!')
                                             ? TokenLib::extractQuotedString(fileData, startPos+1) : TokenLib::stringParseFAILED;
        return result.second != -1 ? TokenizeResult(std::make_shared<TokenMetadataString>(result.first), result.second)
                                   : TokenizeResult();
    }
}