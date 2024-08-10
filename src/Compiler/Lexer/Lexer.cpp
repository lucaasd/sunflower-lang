#include "Lexer.hpp"

SunflowerCompiler::Lexer::Lexer(std::string source)
{
    this->source = source;
}

void SunflowerCompiler::Lexer::Tokenize()
{
}

std::list<char> SunflowerCompiler::Lexer::GetTokens()
{
    return std::list<char>();
}

char SunflowerCompiler::Lexer::CurrentToken()
{
    return 0;
}

void SunflowerCompiler::Lexer::Advance()
{
}
