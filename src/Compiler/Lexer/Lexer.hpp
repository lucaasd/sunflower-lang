#include <string>
#include <list>

namespace SunflowerCompiler
{
    class Lexer
    {
    public:
        Lexer(std::string source);
        std::string source;
        void Tokenize();
        std::list<char> GetTokens();
        char CurrentToken();
        void Advance();

    private:
        std::list<char> tokens;
    };
}