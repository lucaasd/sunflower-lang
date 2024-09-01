#pragma once
#include <vector>
#include <memory>
#include "LiteralNode.hpp"
#include "DeclarationNode.hpp"

namespace SunflowerCompiler
{

    struct ConstNode : DeclarationNode
    {
        std::unique_ptr<LiteralNode> value;
        std::string type;
        std::string name;
        std::string Print();
        ConstNode(std::unique_ptr<LiteralNode> value, std::string type, std::string name) : value(std::move(value)), type(type), name(name) {}
        ~ConstNode();
    };
}