#pragma once

#include "LiteralNode.hpp"
#include <string>

namespace SunflowerCompiler
{
    struct IntegerNode : LiteralNode
    {
        int value;
        std::string Print();
        IntegerNode(int value) : value(value) {}
    };
}