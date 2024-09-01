#include "gtest/gtest.h"
#include "Compiler/Lexer/Lexer.hpp"
#include "Compiler/Parser/Parser.hpp"
#include "Compiler/Parser/RootNode.hpp"
#include "Compiler/Parser/ConstNode.hpp"
#include <vector>
#include <memory>
#include <utility>

using namespace SunflowerCompiler;

TEST(ParserTest, TestIntConst)
{
    std::string source = "const a int = 5";
    Lexer lexer(source);
    lexer.Tokenize();
    std::vector<Token> tokens = lexer.GetTokens();
    Parser parser(tokens);
    parser.Parse();
    RootNode &rootNode = parser.rootNode;
    ConstNode *constNode = dynamic_cast<ConstNode *>(rootNode.nodes[0].get());
    ASSERT_EQ(rootNode.nodes.size(), 1);
    ASSERT_EQ(constNode != nullptr, true);
    ASSERT_EQ(constNode->name, "a");
    ASSERT_EQ(constNode->type, "int");
    ASSERT_EQ(constNode->value->Print(), "5");
    ASSERT_EQ(constNode->Print(), "const a int = 5");
}