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
    CPAREN
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
      {Sintaxe::EQUAL, "EQUAL"},
      {Sintaxe::NOT_EQUAL, "NOT_EQUAL"},
      {Sintaxe::LESS_EQUAL, "LESS_EQUAL"},
      {Sintaxe::GREATER_EQUAL, "GREATER_EQUAL"},
      {Sintaxe::AND, "AND"},
      {Sintaxe::OR, "OR"},
      {Sintaxe::INCREMENT, "INCREMENT"},
      {Sintaxe::DECREMENT, "DECREMENT"},
      {Sintaxe::ADD_EQUAL, "ADD_EQUAL"},
      {Sintaxe::SUB_EQUAL, "SUB_EQUAL"},
      {Sintaxe::GREATER, "GREATER"},
      {Sintaxe::LESS, "LESS"},
      {Sintaxe::ASSIGN, "ASSIGN"},
      {Sintaxe::PLUS, "PLUS"},
      {Sintaxe::RANGE, "RANGE"},
      {Sintaxe::SPREAD, "SPREAD"},
      {Sintaxe::MINUS, "MINUS"},
      {Sintaxe::MULTIPLY, "MULTIPLY"},
      {Sintaxe::DIVIDE, "DIVIDE"},
      {Sintaxe::MODULO, "MODULO"},
      {Sintaxe::CONCAT, "CONCAT"},
      {Sintaxe::NOT, "NOT"},
      {Sintaxe::OBRACKET, "OBRACKET"},
      {Sintaxe::CBRACKET, "CBRACKET"},
      {Sintaxe::OPAREN, "OPAREN"},
      {Sintaxe::CPAREN, "CPAREN"},
  };

  std::string sintaxe_string(Sintaxe sintaxe)
  {
    auto it = sintaxeToString.find(sintaxe);
    return (it != sintaxeToString.end()) ? it->second : "UNKNOWN";
  }

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