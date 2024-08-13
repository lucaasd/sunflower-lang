#include <vector>
#include "Lexer/Token.hpp"

using namespace SunflowerCompiler;

class Parser
{
public:
    Parser();
    void Parse(std::vector<Token>);
};