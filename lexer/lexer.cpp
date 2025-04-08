#include "lexer.hpp"

using namespace lexer;

std::string
Lexer::readFile(const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::ate);
    if (!file.is_open()) {
        throw LexerException("File cannot be opened");
    }
    size_t size = file.tellg();
    file.seekg(0);
    char* buff = new char[size];
    file.read(buff, size);
    return buff;
}

char
Lexer::eatByte()
{
    if (localCursor.position + 1 >= content.size()) {
        return -1;
    }
    return content[localCursor.position++];
}

char
Lexer::peekByte()
{
    if (localCursor.position + 1 >= content.size()) {
        return -1;
    }
    return content[localCursor.position + 1];
}

bool
Lexer::match(char c)
{
    return c == content[localCursor.position];
}

bool
Lexer::match(const std::string& str)
{
    return str.compare(content.substr(localCursor.position, str.size()));
}

Token
Lexer::scanIdentifier()
{
    
}
