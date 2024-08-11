#pragma once

#include <string>
#include <vector>
#include "Token.hpp"

namespace SunflowerCompiler
{
    class Lexer
    {
    public:
        Lexer(std::string sourceCode);
        std::string source;
        void Tokenize();
        std::vector<Token> GetTokens();
        char CurrentChar();
        void Advance();
        void Reset();

    private:
        std::vector<Token> tokens;
        int index = 0;
    };
}
