#include "gtest/gtest.h"
#include "Compiler/Parser/IntegerNode.hpp"

using namespace SunflowerCompiler;

TEST(IntegerNodeTest, TestPrint)
{
    IntegerNode node(5);
    EXPECT_EQ(node.Print(), "5");
}