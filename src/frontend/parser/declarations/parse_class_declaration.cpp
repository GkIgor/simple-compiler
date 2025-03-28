#include "frontend/parser/parser.h"
#include "debbuger/print/print_class_ast.hpp"

namespace frontend::parser
{
  Node *Parser::parse_class_declaration()
  {
    // To-do criar um parse de implements e extends

    Token class_name = current_token();

    if (!match_type("IDENTIFIER"))
    {
      std::string error_message = "Esperava um identificador após CLASS em linha " +
                                  std::to_string(class_name.line);

      throw core::throw_program_error(error_message.c_str());
    };

    Node *class_node = new Node(NodeType::CLASS_DECLARATION);

    class_node->data = ClassDeclarationNode{
        class_name,
        {},
        {},
    };

    expect(symbol_table::sintaxe_string(symbol_table::Sintaxe::OPAREN)); // verifica e consome o "("
    advance();                                                           // pula nome da classe

    while (!match(symbol_table::sintaxe_string(symbol_table::Sintaxe::CPAREN)))
    {
      if (!match_type("IDENTIFIER"))
      {
        std::string error_message = "Esperava um nome de membro em linha " +
                                    std::to_string(current_token().line) + " mas foi encontrado um '" +
                                    peek().lexeme + "'";
        throw core::throw_program_error(error_message.c_str());
      }

      Token member_name = tokens[current_pos - 1];

      if (!match_type("TYPE"))
      {
        std::string error_message = "Esperava um tipo de membro em linha " +
                                    std::to_string(current_token().line) + ", mas foi encontrado um '" +
                                    peek().lexeme + "'";

        throw core::throw_program_error(error_message.c_str());
      }
      Token member_type = tokens[current_pos - 1];

      Node *member_node = new Node(NodeType::VARIABLE_DECLARATION);

      member_node->data = VariableDeclarationNode{
          member_name,
          new Node(NodeType::IDENTIFIER, IdentifierNode{member_type}),
          nullptr,
      };

      std::get<ClassDeclarationNode>(class_node->data).members.push_back(member_node);

      if (peek().lexeme != symbol_table::sintaxe_string(symbol_table::Sintaxe::CPAREN))
      {
        if (!match(symbol_table::sintaxe_string(symbol_table::Sintaxe::COMMA)))
        {
          if (current_token().lexeme != symbol_table::sintaxe_string(symbol_table::Sintaxe::CPAREN))
          {
            std::string error_message = "Esperava ',' ou ')' em linha " +
                                        std::to_string(current_token().line) + ", mas foi encontrado um '" +
                                        peek().lexeme + "'";
            throw core::throw_program_error(error_message.c_str());
          }
        }
      }
    }

    expect(symbol_table::sintaxe_string(symbol_table::Sintaxe::OBRACKET));

    // while (match(symbol_table::sintaxe_string(symbol_table::Sintaxe::CBRACKET)))
    // {
    //   Token member_name = current_token();
    // }

    debugger::print_class_ast(class_node);

    return class_node;
  }

} // namespace
