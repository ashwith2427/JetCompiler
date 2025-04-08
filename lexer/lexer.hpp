#include "types.hpp"
#include "error.hpp"
#include <string>
#include <fstream>

namespace lexer {

class Lexer : public std::vector<Token>
{
  public:
    Lexer(const std::string& file_name):content(readFile(file_name)){}
    void scan();
    std::vector<Token> getTokens() const;

  private:
    std::string readFile(const std::string& file_name);
    char eatByte();
    char peekByte();
    bool match(char c);
    bool match(const std::string& str);
    Token scanIdentifier();
    Token scanKeyword();
    Token scanIntegerLiteral();
    Token scanStringLiteral();
    Token scanDoubleLiteral();
    Token scanComments();
    Token scanSingleLineComment();
    Token scanMultiLineComment();
    Token scanDocString();
    Token scanOperator();
    std::vector<Token> tokens;
    Cursor localCursor;
    Cursor globalCursor;
    std::string content;
};
} // namespace lexer