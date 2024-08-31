#pragma once
#include "Node.hpp"
#include <vector>
#include <memory>

namespace SunflowerCompiler
{
    struct RootNode : Node
    {
    public:
        RootNode() {};
        std::vector<std::unique_ptr<Node>> nodes;
        std::string Print() override;
        ~RootNode();
    };
}