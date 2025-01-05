#ifndef LEXER_H
#define LEXER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef struct LexerToken {
  int start;
  int end;
  std::string type;
  std::string lexeme;
} Token;

namespace frontend {
namespace lexer {
class Tokenize {
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
  void next_token();
  void get_current_token();
  void skip_token();
};

void start_analize_lexical(std::string &filename);

} // namespace lexer

} // namespace frontend

#endif // !LEXER_H
#define LEXER_H
