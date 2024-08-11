#pragma once
#include <string>
#include "TokenType.hpp"

namespace SunflowerCompiler
{
    struct Token
    {
        std::string name;
        TokenType type;
    };
}
