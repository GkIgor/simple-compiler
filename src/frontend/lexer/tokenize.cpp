#include "frontend/lexer/lexer.h"

namespace frontend
{
  namespace lexer
  {
    Tokenize::Tokenize(std::string &filename)
    {
      file.open(filename);
      if (file.is_open())
      {
        Tokenize::read_lines();
      }
    }

    Tokenize::~Tokenize()
    {
      if (file.is_open())
      {
        file.close();
      }
    }

    void Tokenize::read_lines()
    {
      if (!file.is_open())
      {
        std::cerr << "Erro: Arquivo não pode ser aberto!" << std::endl;
        return;
      }

      int line_start = 0;
      int line_number = 1;

      while (std::getline(file, line))
      {
        int pos = 0;
        while (pos < line.length())
        {
          Token token = read_token(line, pos);
          if (!token.lexeme.empty())
          {
            token.start = line_start + pos - token.lexeme.length();
            token.end = line_start + pos;
            token.line = line_number;
            tokens.push_back(token);
          }
        }
        line_number++;
        line_start += line.length() + 1;
      }

      is_eof = file.eof();
    }

    Token Tokenize::read_token(const std::string &line, int &pos)
    {
      while (pos < line.length() && std::isspace(line[pos]))
        pos++; // Ignora espaços

      if (pos >= line.length())
        return {};

      Token token;
      char c = line[pos];

      if (std::isalpha(c) || c == '_') // Identificadores e palavras-chave
      {
        int start = pos;
        while (pos < line.length() && (std::isalnum(line[pos]) || line[pos] == '_'))
          pos++;

        token.lexeme = line.substr(start, pos - start);
        token.type = is_keyword(token.lexeme) ? "KEYWORD" : is_type(token.lexeme) ? "TYPE"
                                                                                  : "IDENTIFIER";
      }
      else if (std::isdigit(c)) // Números
      {
        int start = pos;

        while (pos < line.length() && std::isdigit(line[pos]))
          pos++;

        // Verificar se é um operador ".." em vez de decimal
        if (pos + 1 < line.length() && line[pos] == '.' && line[pos + 1] == '.')
        {
          // Não avançar para ".." aqui; será tratado como operador
        }
        else if (pos < line.length() && line[pos] == '.')
        {
          pos++;
          while (pos < line.length() && std::isdigit(line[pos]))
            pos++;
        }
        token.lexeme = line.substr(start, pos - start);
        token.type = "NUMBER";
      }
      else if (c == '"' || c == '\'') // Strings
      {
        int start = pos;
        char quote = c;
        pos++; // Pular a aspa inicial

        while (pos < line.length() && line[pos] != quote)
          pos++;

        if (pos < line.length())
          pos++; // Pular a aspa final

        token.lexeme = line.substr(start, pos - start);
        token.type = "STRING";
      }
      else if (std::ispunct(c))
      { // Símbolos e operadores
        std::string two_char_symbol = (pos + 1 < line.length()) ? line.substr(pos, 2) : "";
        if (is_operator(two_char_symbol))
        {
          token.lexeme = two_char_symbol;
          token.type = "OPERATOR";
          pos += 2;
        }
        else
        {
          token.lexeme = std::string(1, c);
          token.type = is_operator(token.lexeme) ? "OPERATOR" : "SYMBOL";
          pos++;
        }
      }
      else
      {
        token.lexeme = std::string(1, c);
        token.type = "UNKNOWN";
        pos++;
      }

      return token;
    }

    bool Tokenize::is_operator(const std::string &op)
    {
      return std::find(symbol_table::operators.begin(), symbol_table::operators.end(), op) != symbol_table::operators.end();
    }

    bool Tokenize::is_keyword(const std::string &word)
    {
      return std::find(symbol_table::keywords.begin(), symbol_table::keywords.end(), word) != symbol_table::keywords.end();
    }

    bool Tokenize::is_type(const std::string &word)
    {
      return std::find(symbol_table::types.begin(), symbol_table::types.end(), word) != symbol_table::types.end();
    }

    std::vector<Token> Tokenize::getTokens()
    {
      return tokens;
    }

  } // namespace lexer
} // namespace frontend
