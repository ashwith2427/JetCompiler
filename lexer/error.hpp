#include <exception>
#include <string>

class LexerException: public std::exception{
    std::string msg;
    public:
    LexerException(const std::string& msg): msg("Lexer Exception: "+msg){}
    const char* what() const noexcept override{
        return msg.c_str();
    }
};