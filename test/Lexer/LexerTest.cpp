#include "gtest/gtest.h"
#include <string>
#include <algorithm>
#include "Compiler/Lexer/Lexer.hpp"
#include "Compiler/Lexer/Token.hpp"
#include "Compiler/Lexer/TokenType.hpp"

using namespace SunflowerCompiler;

TEST(LexerTest, TestIdentifier)
{
    std::string source = "main";
    Lexer lexer(source);
    lexer.Tokenize();
    Token token = lexer.GetTokens()[0];
    EXPECT_EQ(token.type, TokenType::SYMBOL);
    EXPECT_EQ(token.name, "main");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
