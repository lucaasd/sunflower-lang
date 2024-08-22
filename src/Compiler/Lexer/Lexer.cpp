#include "Compiler/Lexer/Lexer.hpp"
#include "Compiler/Lexer/Token.hpp"
#include "Compiler/Lexer/TokenType.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace SunflowerCompiler;

std::vector<Token> keywords = {
    Token{"return", TokenType::RETURN},
    Token{"if", TokenType::IF},
    Token{"else", TokenType::ELSE},
    Token{"while", TokenType::WHILE},
    Token{"for", TokenType::FOR},
    Token{"void", TokenType::VOID},
    Token{"null", TokenType::NULL_TOKEN},
};

std::vector<Token> delimiters = {
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

namespace SunflowerCompiler
{
    void Lexer::Tokenize()
    {
        while (CurrentChar() != '\0')
        {
            if (isspace(CurrentChar()))
            {
                Advance();
                continue;
            }
            else if (CurrentChar() == '-')
            {
                char hyphen = CurrentChar();
                Advance();
                if (isdigit(CurrentChar()))
                {
                    Digit(true);
                    continue;
                }
                tokens.push_back(Token{std::string(1, hyphen), TokenType::MINUS});
                continue;
            }
            else if (isdigit(CurrentChar()))
            {
                Digit();
            }
            else if (isalpha(CurrentChar()))
            {
                int start = index;
                Keyword();
            }
            else if (CurrentChar() == '\'')
            {
                Char();
                continue;
            }
            else
            {
                char currentChar = CurrentChar();
                auto it = std::find_if(
                    delimiters.begin(),
                    delimiters.end(),
                    [&currentChar](const Token &token)
                    {
                        return token.name == std::string(1, currentChar);
                    });

                if (it != delimiters.end())
                {
                    tokens.push_back(Token{
                        std::string{CurrentChar()},
                        it->type});
                }
                else
                {
                    tokens.push_back(Token{std::string{CurrentChar()}, TokenType::UNKNOWN});
                }
            }
            Advance();
        }
    }

    void Lexer::Keyword()
    {
        int start = index;
        while (isalpha(CurrentChar()))
        {
            Advance();
        }
        std::string value = source.substr(start, index - start);
        std::cerr << value << std::endl;
        auto it = std::find_if(
            keywords.begin(), keywords.end(),
            [value](Token const &token)
            {
                return token.name == value;
            });
        if (it != keywords.end())
        {
            tokens.push_back(Token{value, it->type});
            return;
        }
        tokens.push_back(Token{value, TokenType::SYMBOL});
    }

    void Lexer::Digit(bool isNegative)
    {
        int start = index;
        bool hasDot;
        bool passedDecimal = false;
        while (isalnum(CurrentChar()) || CurrentChar() == '.')
        {
            if (CurrentChar() == '.')
            {
                if (hasDot)
                {
                    tokens.push_back(Token{source.substr(start, index - start), TokenType::UNKNOWN});
                    break;
                }
                hasDot = true;
            }

            if (isalpha(CurrentChar()) && !passedDecimal && hasDot)
            {
                int start = index;
                while (isalnum(CurrentChar()))
                {
                    Advance();
                }
                std::string value = source.substr(start, index - start);

                if (std::any_of(value.begin(), value.end(), ::isdigit))
                {
                    tokens.push_back(Token{value, TokenType::UNKNOWN});
                    break;
                }
                passedDecimal = true;
            }
            Advance();
        }

        std::string value = source.substr(start, index - start);
        isNegative ? value = "-" + value : value;
        if (hasDot)
        {
            tokens.push_back(Token{value, TokenType::FLOAT_NUMBER});
        }
        else
        {
            tokens.push_back(Token{value, TokenType::INT_NUMBER});
        }
    }

    void Lexer::Char()
    {
        int start = index;
        if (CurrentChar() == '\'')
        {
            Advance();
            Advance();
        }
        std::string value = source.substr(start, (index - start) + 1);
        if (CurrentChar() != '\'')
        {
            tokens.push_back(Token{value, TokenType::UNKNOWN});
            return;
        }
        tokens.push_back(Token{value, TokenType::CHAR});
    }

    void Lexer::Advance()
    {
        if (index < source.size())
        {
            index++;
        }
    }

    char Lexer::CurrentChar()
    {
        return source[index];
    }

    std::vector<Token> Lexer::GetTokens()
    {
        return tokens;
    }
}