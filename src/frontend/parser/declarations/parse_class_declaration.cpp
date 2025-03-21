#include "frontend/parser/parser.h"

namespace frontend::parser
{
  Node *Parser::parse_class_declaration()
  {
    Node *node_class = new Node(NodeType::CLASS_DECLARATION);

    if (node_class != nullptr)
    {
      advance(); // pula declaração de classe
      if (match_type("IDENTIFIER"))
      {
        node_class->data = IdentifierNode{
            current_token(),
        };
        advance(); // pula nome da classe
      };

      // To-do criar um parse de implements e extends

      if (match(symbol_table::sintaxe_string(symbol_table::Sintaxe::OPAREN)))
      {
        while (!match(symbol_table::sintaxe_string(symbol_table::Sintaxe::CPAREN)))
        {
          // TO-DO terminar esse parse
          /* code */
        }
      }
    }

    return node_class;
  }

} // namespace
