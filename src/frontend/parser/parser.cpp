#include "parser.h"

namespace frontend
{
  namespace parser
  {

    AstProgram *start_parse(const std::vector<Token> &tokens)
    {
      AstProgram ast(tokens);

      return &ast;
    }

  } // namespace parser

} // namespace frontend
