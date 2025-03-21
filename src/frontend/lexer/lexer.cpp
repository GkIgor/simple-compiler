#include "frontend/lexer/lexer.h"

namespace frontend
{
  namespace lexer
  {
    Tokenize *start_analize_lexical(std::string &filename)
    {
      Tokenize *tokenizer = new Tokenize(filename);

      std::vector<Token> tokens = tokenizer->getTokens();

      for (auto it = tokens.begin(); it != tokens.end(); ++it)
      {
        print(*it);
      }

      return tokenizer;
    }
  } // namespace lexer
} // namespace frontend

void print(const Token &token)
{
  constexpr int WIDTH = 20; // Define um tamanho fixo para alinhamento
  std::cout << "| " << token.line << "    " << std::setw(WIDTH) << std::left << token.lexeme
            << " --> " << token.type << std::endl;
}