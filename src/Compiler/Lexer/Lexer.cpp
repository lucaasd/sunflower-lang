#include "Lexer.hpp"
#include "Token.hpp"
#include "TokenType.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace SunflowerCompiler;

std::vector<Token> defaultTokens = {
    Token{"return", TokenType::RETURN},
    Token{"if", TokenType::IF},
    Token{"else", TokenType::ELSE},
    Token{"while", TokenType::WHILE},
    Token{"for", TokenType::FOR},
    Token{"void", TokenType::VOID},
    Token{"(", TokenType::LEFT_PAREN},
    Token{")", TokenType::RIGHT_PAREN},
    Token{"{", TokenType::LEFT_BRACE},
    Token{"}", TokenType::RIGHT_BRACE},
    Token{",", TokenType::COMMA},
    Token{".", TokenType::DOT},
    Token{"-", TokenType::MINUS},
    Token{"+", TokenType::PLUS},
    Token{";", TokenType::SEMICOLON},
    Token{"/", TokenType::SLASH},
    Token{"*", TokenType::STAR},
    Token{"!", TokenType::BANG},
    Token{"!=", TokenType::BANG_EQUAL},
    Token{"=", TokenType::SET_EQUAL},
    Token{"==", TokenType::EQUAL},
};

SunflowerCompiler::Lexer::Lexer(std::string sourceCode)
{
    this->source = sourceCode;
    index = 0;
}

void SunflowerCompiler::Lexer::Tokenize()
{
    index = 0;
    while (CurrentChar() != '\0')
    {
        if (isalpha(CurrentChar()))
        {
            int start = index;
            while (isalpha(CurrentChar()))
            {
                Advance();
            }

            std::string value = source.substr(start, index - start);
            auto it = std::find_if(
                defaultTokens.begin(),
                defaultTokens.end(),
                [&value](const Token &_token)
                {
                    return _token.name == value;
                });
            if (it != defaultTokens.end())
            {
                tokens.push_back(Token{value, it->type});
            }
            else
            {
                tokens.push_back(Token{value, TokenType::SYMBOL});
            }
            continue;
        }

        else if (isspace(CurrentChar()))
        {
            int start = index;
            Advance();
            continue;
        }
        else if (isdigit(CurrentChar()))
        {
            int start = index;
            Advance();
            continue;
        }
        else
        {
            std::string value = std::string(1, source[index]);
            std::cout << "Value: " << value << std::endl;
            auto it = std::find_if(
                defaultTokens.begin(),
                defaultTokens.end(),
                [&value](const Token &_token)
                {
                    return _token.name == value;
                });
            if (it != defaultTokens.end())
            {
                std::cout << "Token: " << it->name << std::endl;
                tokens.push_back(Token{value, it->type});
            }
            else
            {
                tokens.push_back(Token{value, TokenType::UNKNOWN});
            }
            Advance();
            continue;
        }
        continue;
    }
}

std::vector<Token> SunflowerCompiler::Lexer::GetTokens()
{
    return tokens;
}

char SunflowerCompiler::Lexer::CurrentChar()
{
    if (index < source.length())
    {
        return source[index];
    }
    return '\0';
}

void SunflowerCompiler::Lexer::Advance()
{
    if (index < source.length())
    {
        index++;
    }
}

void SunflowerCompiler::Lexer::Reset()
{
    index = 0;
}
