#include "frontend/parser/parser.h"

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

    Node *Parser::parse()
    {
      root = new Node(NodeType::PROGRAM);
      root->data = ProgramNode{
          "unknow_os",
          "unknow_arch",
          {},
      };

      while (current_pos < tokens.size())
      {
        Token tok = current_token();

        if (match("CLASS"))
        {
          Node *class_node = parse_class_declaration();

          std::get<ProgramNode>(root->data).declarations.push_back(class_node);
        }
        else if (match("FN"))
        {
          Node *func_node = parse_function_declaration();

          std::get<ProgramNode>(root->data).declarations.push_back(func_node);
        }
        else if (match("RUN"))
        {
          Node *run_node = parse_function_call();

          std::get<ProgramNode>(root->data).declarations.push_back(run_node);
          expect(";"); // espera um ;
        }
        else
        {
          // Token inesperado
          Node *unknown_node = new Node(NodeType::UNKNOWN);
          unknown_node->data = LiteralNode{tok}; // depois eu vejo o que fazer nessa bagaça

          std::get<ProgramNode>(root->data).declarations.push_back(unknown_node);
          advance();
        }
      }

      return root;
    }

  } // namespace lexer

} // namespace fronted
