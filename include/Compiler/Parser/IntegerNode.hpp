#pragma once

#include "Node.hpp"
#include <string>

namespace SunflowerCompiler
{
    struct IntegerNode : Node
    {
        int value;
        std::string Print();
        IntegerNode(int value) : value(value) {}
    };
}