#include "Compiler/Parser/IntegerNode.hpp"

namespace SunflowerCompiler
{
    std::string IntegerNode::Print()
    {
        return std::to_string(value);
    }
}
