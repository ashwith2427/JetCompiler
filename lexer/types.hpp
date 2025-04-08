#include <cstdint>
#include <map>
#include <string>
#include <vector>
#include <optional>

#undef EOF
enum class TokenType {
  IDENTIFIER,
  STRING_LITERAL,
  INTEGER_LITERAL,
  DOUBLE_LITERAL,
  KEYWORD,
  LEFT_BRACKET,
  RIGHT_BRACKET,
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  SEMICOLON,
  COLON,
  COMMA,
  DOT,
  SINGLE_QUOTE,
  DOUBLE_QUOTE,
  ADD,
  MINUS,
  DIVIDE,
  MODULO,
  MULTIPLY,
  ASSIGN,
  EQUALS,
  ADD_ASSIGN,
  MINUS_ASSIGN,
  MULTIPLY_ASSIGN,
  MODULO_ASSIGN,
  AND_ASSIGN,
  OR_ASSIGN,
  XOR_ASSIGN,
  BIT_AND,
  BIT_OR,
  BIT_XOR,
  COMMENT,
  MULTILINE_COMMENT,
  DOC_COMMENT,
  GREATER_THAN,
  LESS_THAN,
  NOT,
  NOT_EQUALS,
  GREATER_THAN_EQUALS,
  LESS_THAN_EQUALS,
  PLUS_PLUS,
  MINUS_MINUS,
  EOF,
};

enum class OperatorKind{
  ARITHMETIC_OPERATOR,
  RELATIONAL_OPERATOR,
  BITWISE_OPERATOR,
  UNARY_OPERATOR,
  ASSIGNMENT_OPERATOR,
};

const std::map<std::string, OperatorKind> mapOperators = {
    {"+", OperatorKind::ARITHMETIC_OPERATOR},
    {"-", OperatorKind::ASSIGNMENT_OPERATOR},
    {"/", OperatorKind::ARITHMETIC_OPERATOR},
    {"*", OperatorKind::ARITHMETIC_OPERATOR},
    {"&", OperatorKind::BITWISE_OPERATOR},
    {"^", OperatorKind::BITWISE_OPERATOR},
    {"|", OperatorKind::BITWISE_OPERATOR},
    {"+=", OperatorKind::ASSIGNMENT_OPERATOR},
    {"-=", OperatorKind::ASSIGNMENT_OPERATOR},
    {"*=", OperatorKind::ASSIGNMENT_OPERATOR},
    {"&=", OperatorKind::ASSIGNMENT_OPERATOR},
    {"^=", OperatorKind::ASSIGNMENT_OPERATOR},
    {"|=", OperatorKind::ASSIGNMENT_OPERATOR},
    {"!=", OperatorKind::RELATIONAL_OPERATOR},
    {"==", OperatorKind::RELATIONAL_OPERATOR},
    {">=", OperatorKind::RELATIONAL_OPERATOR},
    {"<=", OperatorKind::RELATIONAL_OPERATOR},
    {"++", OperatorKind::UNARY_OPERATOR},
    {"--", OperatorKind::UNARY_OPERATOR},
};

const std::vector<std::string> keywords = {
    "abstract",  "and",      "assert",     "boolean",  "break",
    "byte",      "case",     "catch",      "char",     "class",
    "const",     "continue", "default",    "do",       "double",
    "else",      "enum",     "extends",    "false",    "final",
    "finally",   "float",    "for",        "if",       "implements",
    "import",    "in",       "instanceof", "int",      "interface",
    "is",        "lazy",     "long",       "native",   "new",
    "not",       "null",     "or",         "package",  "private",
    "protected", "public",   "range",      "return",   "short",
    "static",    "strictfp", "super",      "switch",   "synchronized",
    "then",      "this",     "throw",      "throws",   "transient",
    "true",      "try",      "void",       "volatile", "while",
    "with",
};

struct Cursor
{
    uint32_t position;
    uint32_t line;
    Cursor operator++(int)
    {
        Cursor tmp = *this;
        ++position;
        return tmp;
    }
};

struct Token{
    uint32_t line;
    uint32_t column;
    std::string lexeme;
    TokenType type;
    std::optional<OperatorKind> opkind;
};