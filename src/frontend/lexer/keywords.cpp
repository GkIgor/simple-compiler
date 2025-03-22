#include "frontend/lexer/keywords.h"

namespace symbol_table
{
  std::string sintaxe_string(Sintaxe sintaxe)
  {
    auto it = sintaxeToString.find(sintaxe);
    return (it != sintaxeToString.end()) ? it->second : "UNKNOWN";
  }
} // namespace symbol_table
