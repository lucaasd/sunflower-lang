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

TEST(LexerTest, TestIdentifierWithMultipleTokens)
{
    std::string expectedName = "main";
    TokenType expectedType = TokenType::SYMBOL;
    std::string source = "void main() {}";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    auto it = std::find_if(
        tokens.begin(),
        tokens.end(),
        [&expectedName, &expectedType](const Token &token)
        {
            return token.name == expectedName && token.type == expectedType;
        });
    if (it != tokens.end())
    {
        EXPECT_EQ(it->name, expectedName);
        EXPECT_EQ(it->type, expectedType);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
