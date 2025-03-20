#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "keywords.h"
#include <iomanip>

typedef struct LexerToken
{
  size_t line;
  int start;
  int end;
  std::string type;
  std::string lexeme;
} Token;

void print(const Token &token);

namespace frontend
{
  namespace lexer
  {
    class Tokenize
    {
    private:
      std::ifstream file;
      char ch;
      std::vector<Token> tokens;
      std::string line;
      bool is_eof;
      Token current_token;
      void read_lines();

    public:
      explicit Tokenize(std::string &filename);
      ~Tokenize();
      std::vector<Token> getTokens();
      std::string read_char(int &pos);
      bool is_operator(const std::string &op);
      Token read_token(const std::string &line, int &pos);
      bool is_keyword(const std::string &word);
      bool is_type(const std::string &word);
    };

    void start_analize_lexical(std::string &filename);

  } // namespace lexer

} // namespace frontend

#endif // !LEXER_H
#define LEXER_H
