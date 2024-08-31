#include "Node.hpp"

namespace SunflowerCompiler
{
    struct DeclarationNode : Node
    {
        virtual std::string Print() = 0;
        virtual ~DeclarationNode() = default;
    };
}