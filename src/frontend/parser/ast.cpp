#include "parser.h"

namespace frontend
{
  namespace parser
  {
    Parser::Parser(const std::vector<Token> &lexer_tokens)
    {
      if (&lexer_tokens != nullptr && lexer_tokens.size() > 0)
      {
        this->tokens = lexer_tokens;
        this->current_pos = 0;
        this->root = nullptr;
      }
      else
      {
        core::throw_program_error("Error: No tokens found!");
      }
    }

    Parser::~Parser()
    {
      if (this->root != nullptr)
      {
        delete this->root;
      }
      this->root = nullptr;
    }

    Token Parser::current_token() const
    {
      if (this->current_pos < this->tokens.size())
      {
        return this->tokens[this->current_pos];
      }

      return empty_token;
    }

    Token Parser::peek() const
    {
      if (this->current_pos + 1 < this->tokens.size())
      {
        return this->tokens[this->current_pos + 1];
      }

      return empty_token;
    }

    void Parser::advance()
    {
      if (this->current_pos + 1 < this->tokens.size())
      {
        current_pos++;
      }
    }

    bool Parser::match(const std::string &lexeme)
    {
      if (this->current_pos < this->tokens.size() && tokens[current_pos].lexeme == lexeme)
      {
        this->advance();
        return true;
      }
      return false;
    }

    bool Parser::match_type(const std::string &type)
    {
      if (this->current_pos < this->tokens.size() && tokens[current_pos].type == type)
      {
        this->advance();
        return true;
      }
      return false;
    }

    void Parser::expect(const std::string &lexeme)
    {
      if (this->current_pos >= this->tokens.size() || this->tokens[this->current_pos].lexeme != lexeme)
      {
        std::string message = "Expected '" + lexeme + "' but found '" + (this->current_pos < this->tokens.size() ? this->current_token().lexeme : "EOF") + "'";

        core::throw_program_error(message.c_str());
      }
    }

    void parser()
    {
    }

  } // namespace lexer

} // namespace fronted
