#include "Compiler/Parser/Parser.hpp"
#include "Compiler/Parser/RootNode.hpp"
#include "Compiler/Parser/IntegerNode.hpp"
#include "Compiler/Parser/ConstNode.hpp"
#include "magic_enum/magic_enum.hpp"
#include "memory"
#include <stdexcept>
#include <format>
#include <iostream>

namespace SunflowerCompiler
{

    void Parser::Parse()
    {
        if (tokens.empty())
        {
            throw std::runtime_error("No tokens to parse");
        }

        while (CurrentToken().type != TokenType::END_OF_FILE)
        {
            if (depth == 0)
            {
                Token startToken = CurrentToken();
                if (startToken.type == TokenType::CONST)
                {
                    std::string type;
                    std::string name;
                    Advance();
                    if (CurrentToken().type != TokenType::SYMBOL)
                    {
                        throw std::runtime_error("Expected identifier after 'const'");
                    }
                    name = CurrentToken().name;
                    Advance();
                    if (CurrentToken().type != TokenType::SYMBOL)
                    {
                        throw std::runtime_error(std::format("Expected type after '{}'", CurrentToken().name));
                    }
                    type = CurrentToken().name;
                    Advance();
                    if (CurrentToken().type != TokenType::SET_EQUAL)
                    {
                        throw std::runtime_error(std::format("Expected '=' after {}", type));
                    }
                    Advance();
                    if (CurrentToken().type == TokenType::INT_NUMBER)
                    {
                        std::unique_ptr<IntegerNode> integerNode = std::make_unique<IntegerNode>(std::stoi(CurrentToken().name));
                        std::unique_ptr<ConstNode> constNode = std::make_unique<ConstNode>(std::move(integerNode), type, name);
                        rootNode.nodes.push_back(std::move(constNode));
                    }
                    else
                    {
                        throw std::runtime_error("Expected value after '='");
                    }
                    continue;
                }
                Advance();
            }
        }
    }

    void Parser::Advance()
    {
        if (index < tokens.size() - 1)
        {
            index++;
        }
    }

    Token Parser::CurrentToken()
    {
        return tokens[index];
    }
}