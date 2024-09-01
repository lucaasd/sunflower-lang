#include <vector>
#include "RootNode.hpp"
#include "Compiler/Lexer/Token.hpp"

namespace SunflowerCompiler
{
    class Parser
    {
    public:
        Parser(std::vector<Token> source) : tokens(source) {}
        void Parse();
        Token CurrentToken();
        void Advance();
        RootNode rootNode = RootNode{};
        int index = 0;
        int depth = 0;

    private:
        std::vector<Token> tokens;
    };
}