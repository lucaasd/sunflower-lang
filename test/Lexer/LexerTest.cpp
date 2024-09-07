#include "gtest/gtest.h"
#include <string>
#include <algorithm>
#include "Compiler/Lexer/Lexer.hpp"
#include "Compiler/Lexer/Token.hpp"
#include "Compiler/Lexer/TokenType.hpp"
#include "magic_enum/magic_enum.hpp"

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

TEST(LexerTest, TestInteger)
{
    std::string source = "123";
    Lexer lexer(source);
    lexer.Tokenize();
    Token token = lexer.GetTokens()[0];
    std::cout << magic_enum::enum_name(token.type) << std::endl;
    std::cout << token.name << std::endl;
    EXPECT_EQ(token.type, TokenType::INT_NUMBER);
    EXPECT_EQ(token.name, "123");
}

TEST(LexerTest, TestNegativeInteger)
{
    std::string source = "-123";
    Lexer lexer(source);
    lexer.Tokenize();
    Token token = lexer.GetTokens()[0];
    std::cout << magic_enum::enum_name(token.type) << std::endl;
    std::cout << token.name << std::endl;
    EXPECT_EQ(token.type, TokenType::INT_NUMBER);
    EXPECT_EQ(token.name, "-123");
}

TEST(LexerTest, TestFloat)
{
    std::string source = "123.456";
    Lexer lexer(source);
    lexer.Tokenize();
    Token token = lexer.GetTokens()[0];
    std::cout << magic_enum::enum_name(token.type) << std::endl;
    std::cout << token.name << std::endl;
    EXPECT_EQ(token.type, TokenType::FLOAT_NUMBER);
    EXPECT_EQ(token.name, "123.456");
}

TEST(LexerTest, TestNegativeFloat)
{
    std::string source = "-123.456";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    Token token = tokens[0];
    std::cout << magic_enum::enum_name(token.type) << std::endl;
    std::cout << token.name << std::endl;
    EXPECT_EQ(token.type, TokenType::FLOAT_NUMBER);
    EXPECT_EQ(token.name, "-123.456");
    std::cout << "Tokens" << std::endl;
    for (const Token &token : tokens)
    {
        std::cout << token.name << " " << magic_enum::enum_name(token.type) << std::endl;
    }
}

TEST(LexerTest, TestChar)
{
    std::string source = "'a'";
    Lexer lexer(source);
    lexer.Tokenize();
    Token token = lexer.GetTokens()[0];
    std::cout << magic_enum::enum_name(token.type) << std::endl;
    std::cout << token.name << std::endl;
    EXPECT_EQ(token.type, TokenType::CHAR);
    EXPECT_EQ(token.name, "'a'");
}

TEST(LexerTest, TestCharWithMultipleTokens)
{
    std::string source = "return 'a'";
    Lexer lexer(source);
    lexer.Tokenize();
    Token token = lexer.GetTokens()[1];
    std::cout << magic_enum::enum_name(token.type) << std::endl;
    std::cout << token.name << std::endl;
    EXPECT_EQ(token.type, TokenType::CHAR);
    EXPECT_EQ(token.name, "'a'");
}

TEST(LexerTest, TestVariableDeclaration)
{
    std::string source = "var a int = 0";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    EXPECT_EQ(tokens[0].name, "var");
    EXPECT_EQ(tokens[1].name, "a");
    EXPECT_EQ(tokens[2].name, "int");
    EXPECT_EQ(tokens[3].name, "=");
    EXPECT_EQ(tokens[4].name, "0");
    EXPECT_EQ(tokens[0].type, TokenType::VAR);
    EXPECT_EQ(tokens[1].type, TokenType::SYMBOL);
    EXPECT_EQ(tokens[2].type, TokenType::SYMBOL);
    EXPECT_EQ(tokens[3].type, TokenType::SET_EQUAL);
    EXPECT_EQ(tokens[4].type, TokenType::INT_NUMBER);
}

TEST(LexerTest, TestConstantDeclaration)
{
    std::string source = "const a int = 5";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    EXPECT_EQ(tokens[0].name, "const");
    EXPECT_EQ(tokens[1].name, "a");
    EXPECT_EQ(tokens[2].name, "int");
    EXPECT_EQ(tokens[3].name, "=");
    EXPECT_EQ(tokens[4].name, "5");
    EXPECT_EQ(tokens[0].type, TokenType::CONST);
    EXPECT_EQ(tokens[1].type, TokenType::SYMBOL);
    EXPECT_EQ(tokens[2].type, TokenType::SYMBOL);
    EXPECT_EQ(tokens[3].type, TokenType::SET_EQUAL);
    EXPECT_EQ(tokens[4].type, TokenType::INT_NUMBER);
}

TEST(LexerTest, TestPrefixedNumber)
{
    std::string source = "0x80";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    EXPECT_EQ(tokens[0].name, "0x80");
    std::cout << magic_enum::enum_name(tokens[0].type) << std::endl;
    EXPECT_EQ(tokens[0].type, TokenType::PREFIXED_NUMBER);
}

TEST(LexerTest, TestPrefixedNumberWithLongPrefix)
{
    std::string source = "0bin01111000";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    EXPECT_EQ(tokens[0].name, "0bin01111000");
    std::cout << magic_enum::enum_name(tokens[0].type) << std::endl;
    EXPECT_EQ(tokens[0].type, TokenType::PREFIXED_NUMBER);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
