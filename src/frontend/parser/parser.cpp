#include "frontend/parser/parser.h"

namespace frontend
{
  namespace parser
  {
    const Token empty_token = Token{0, 0, 0, "EOF", ""};

    Parser *start_parse(const std::vector<Token> &tokens)
    {
      Parser *parser = new Parser(tokens);

      if (parser != nullptr)
      {
        parser->parse();
      }

      return parser;
    }

  } // namespace parser

} // namespace frontend
