#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <string>
#include <vector>
#include <unordered_map>

namespace symbol_table
{
  enum class Sintaxe
  {
    CLASS,
    FN,
    VAR,
    IF,
    ELSE,
    FOR,
    IN,
    WHILE,
    NEW,
    PRINT,
    RUN,
    RETURN,
    THIS,
    EQUAL,
    NOT_EQUAL,
    LESS_EQUAL,
    GREATER_EQUAL,
    AND,
    OR,
    INCREMENT,
    DECREMENT,
    ADD_EQUAL,
    SUB_EQUAL,
    GREATER,
    LESS,
    ASSIGN,
    PLUS,
    RANGE,
    SPREAD,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULO,
    CONCAT,
    NOT,
    OBRACKET,
    CBRACKET,
    OPAREN,
    CPAREN,
    COMMA,
    SEMICOLON,
  };

  const std::unordered_map<Sintaxe, std::string> sintaxeToString = {
      {Sintaxe::CLASS, "CLASS"},
      {Sintaxe::FN, "FN"},
      {Sintaxe::VAR, "VAR"},
      {Sintaxe::IF, "IF"},
      {Sintaxe::ELSE, "ELSE"},
      {Sintaxe::FOR, "FOR"},
      {Sintaxe::IN, "IN"},
      {Sintaxe::WHILE, "WHILE"},
      {Sintaxe::NEW, "NEW"},
      {Sintaxe::PRINT, "PRINT"},
      {Sintaxe::RUN, "RUN"},
      {Sintaxe::RETURN, "RETURN"},
      {Sintaxe::THIS, "THIS"},
      {Sintaxe::EQUAL, "="},
      {Sintaxe::NOT_EQUAL, "!="},
      {Sintaxe::LESS_EQUAL, "<="},
      {Sintaxe::GREATER_EQUAL, ">="},
      {Sintaxe::AND, "&&"},
      {Sintaxe::OR, "||"},
      {Sintaxe::INCREMENT, "++"},
      {Sintaxe::DECREMENT, "--"},
      {Sintaxe::ADD_EQUAL, "+="},
      {Sintaxe::SUB_EQUAL, "-="},
      {Sintaxe::GREATER, ">"},
      {Sintaxe::LESS, "<"},
      {Sintaxe::ASSIGN, "="},
      {Sintaxe::PLUS, "+"},
      {Sintaxe::RANGE, ".."},
      {Sintaxe::SPREAD, "..."},
      {Sintaxe::MINUS, "-"},
      {Sintaxe::MULTIPLY, "*"},
      {Sintaxe::DIVIDE, "/"},
      {Sintaxe::MODULO, "%"},
      {Sintaxe::CONCAT, "||"},
      {Sintaxe::NOT, "!"},
      {Sintaxe::OBRACKET, "{"},
      {Sintaxe::CBRACKET, "}"},
      {Sintaxe::OPAREN, "("},
      {Sintaxe::CPAREN, ")"},
      {Sintaxe::COMMA, ","},
      {Sintaxe::SEMICOLON, ";"},
  };

  std::string sintaxe_string(Sintaxe sintaxe);

  static const std::vector<std::string> keywords = {
      "CLASS",
      "FN",
      "VAR",
      "IF",
      "ELSE",
      "FOR",
      "IN",
      "WHILE",
      "NEW",
      "PRINT",
      "RUN",
      "return",
      "this",
  };

  static const std::vector<std::string> types = {
      "TEXT",
      "INT",
      "FLOAT",
      "LONG",
      "BOOL",
      "CHAR",
      "VOID",
      "NULL",
  };

  static const std::vector<std::string> operators = {
      "==",
      "!=",
      "<=",
      ">=",
      "&&",
      "||",
      "++",
      "--",
      "+=",
      "-=",
      ">",
      "<",
      "=",
      "+",
      "..",
      "...",
      "-",
      "*",
      "/",
      "%",
  };

} // namespace symbol_table

#endif // KEYWORDS_H