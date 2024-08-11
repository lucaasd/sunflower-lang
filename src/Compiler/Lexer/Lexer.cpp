#include "Lexer.hpp"
#include "Token.hpp"
#include "Tokens.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace SunflowerCompiler;

std::vector<Token> defaultTokens = {
    Token{"return", Tokens::RETURN},
    Token{"if", Tokens::IF},
    Token{"else", Tokens::ELSE},
    Token{"while", Tokens::WHILE},
    Token{"for", Tokens::FOR},
    Token{"void", Tokens::VOID},
    Token{"(", Tokens::LEFT_PAREN},
    Token{")", Tokens::RIGHT_PAREN},
    Token{"{", Tokens::LEFT_BRACE},
    Token{"}", Tokens::RIGHT_BRACE},
    Token{",", Tokens::COMMA},
    Token{".", Tokens::DOT},
    Token{"-", Tokens::MINUS},
    Token{"+", Tokens::PLUS},
    Token{";", Tokens::SEMICOLON},
    Token{"/", Tokens::SLASH},
    Token{"*", Tokens::STAR},
    Token{"!", Tokens::BANG},
    Token{"!=", Tokens::BANG_EQUAL},
    Token{"=", Tokens::SET_EQUAL},
    Token{"==", Tokens::EQUAL},
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
        int start = index;

        if (isalpha(CurrentChar()))
        {
            while (isalpha(CurrentChar()))
            {
                Advance();
            }

            std::string value = source.substr(start, index - start);
            auto it = std::find_if(
                defaultTokens.begin(),
                defaultTokens.end(),
                [&value](const Token &person)
                {
                    return person.name == value;
                });
            if (it != defaultTokens.end())
            {
                tokens.push_back(Token{value, it->type});
            }
            else
            {
                tokens.push_back(Token{value, Tokens::IDENTIFIER});
            }
        }
        else
        {
            Advance();
        }
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
