#include <iostream>
#include "Compiler/Lexer/Lexer.hpp"
#include "Compiler/Lexer/Token.hpp"
#include "Compiler/Lexer/TokenType.hpp"
#include "../magic-enum/include/magic_enum/magic_enum.hpp"
#include <vector>

/*
 * this is a temporary example, it will be removed and tests will be added.
 * The main function will only compile the code
 */
std::string source = "int sum(int a, int b) { return a + b; }";

using namespace SunflowerCompiler;

int main()
{
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    for (auto &token : tokens)
    {
        std::cout << token.name << " " << magic_enum::enum_name(token.type) << std::endl;
    }
    return 0;
}