#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <string>
#include <vector>

namespace symbol_table
{
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