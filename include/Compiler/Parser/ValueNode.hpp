#include "Node.hpp"

namespace SunflowerCompiler
{
    struct ValueNode : Node
    {
        virtual std::string Print() = 0;
        virtual ~ValueNode() = default;
    };
}