#pragma once
#include <string>

namespace SunflowerCompiler
{

    struct Node
    {
        virtual ~Node() = default;
        virtual std::string Print() = 0;
    };
}