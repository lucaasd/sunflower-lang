#pragma once

namespace SunflowerCompiler
{
    enum class TokenType
    {
        RETURN,
        IF,
        ELSE,
        WHILE,
        FOR,
        NULL_TOKEN,
        VOID,
        LEFT_PAREN,
        RIGHT_PAREN,
        LEFT_BRACE,
        RIGHT_BRACE,
        COMMA,
        DOT,
        MINUS,
        PLUS,
        SEMICOLON,
        SLASH,
        STAR,
        BANG,
        BANG_EQUAL,
        EQUAL,
        SET_EQUAL,
        GREATER,
        GREATER_EQUAL,
        LESS,
        LESS_EQUAL,
        SYMBOL,
        UNKNOWN
    };
}