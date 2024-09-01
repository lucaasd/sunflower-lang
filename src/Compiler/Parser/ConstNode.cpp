#include "Compiler/Parser/ConstNode.hpp"
#include "Compiler/Parser/LiteralNode.hpp"
#include <format>

namespace SunflowerCompiler
{
    std::string ConstNode::Print()
    {
        return std::format("const {} {} = {}", name, type, value->Print());
    }

    ConstNode::~ConstNode()
    {
    }
}