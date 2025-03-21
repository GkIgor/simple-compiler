#include "frontend/lexer/lexer.h"
#include "frontend/parser/parser.h"

int main(int argc, char *argv[])
{
  std::string path_name{};

  if (argc >= 2)
  {
    path_name = argv[argc - 1];
  }
  else
  {
    core::printRed("Error:\n No file selected!\n");
  }

  frontend::lexer::Tokenize *tokenize = frontend::lexer::start_analize_lexical(path_name);
  frontend::parser::AstProgram *ast = frontend::parser::start_parse(tokenize->getTokens());

  return 0;
}
