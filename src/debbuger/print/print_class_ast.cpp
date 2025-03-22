#include "debbuger/print/print_class_ast.hpp"

namespace debugger
{
  // Função pra imprimir a AST de uma classe com indentação
  void print_class_ast(const Node *node, int indent)
  {
    if (!node || node->type != NodeType::CLASS_DECLARATION)
    {
      std::cout << std::string(indent, ' ') << "Erro: Nó inválido ou não é uma classe\n";
      return;
    }

    const auto &class_data = std::get<ClassDeclarationNode>(node->data);

    // Imprimir o nome da classe
    std::cout << std::string(indent, ' ') << "Class: " << class_data.name.lexeme
              << " (linha " << class_data.name.line << ")\n";

    // Imprimir os membros
    std::cout << std::string(indent + 2, ' ') << "Members:\n";
    for (const Node *member : class_data.members)
    {
      if (member->type == NodeType::VARIABLE_DECLARATION)
      {
        const auto &var_data = std::get<VariableDeclarationNode>(member->data);
        std::cout << std::string(indent + 4, ' ') << "Variable: " << var_data.name.lexeme;
        if (var_data.type)
        {
          const auto &type_data = std::get<IdentifierNode>(var_data.type->data);
          std::cout << " " << type_data.name.lexeme;
        }
        std::cout << " (linha " << var_data.name.line << ")\n";
      }
    }

    // Imprimir os métodos
    std::cout << std::string(indent + 2, ' ') << "Methods:\n";
    for (const Node *method : class_data.methods)
    {
      if (method->type == NodeType::FUNCTION_DECLARATION)
      {
        const auto &func_data = std::get<FunctionDeclarationNode>(method->data);
        std::cout << std::string(indent + 4, ' ') << "Function: " << func_data.name.lexeme
                  << " (linha " << func_data.name.line << ")\n";

        // Parâmetros
        std::cout << std::string(indent + 6, ' ') << "Parameters:\n";
        for (const Node *param : func_data.parameters)
        {
          if (param->type == NodeType::VARIABLE_DECLARATION)
          {
            const auto &param_data = std::get<VariableDeclarationNode>(param->data);
            std::cout << std::string(indent + 8, ' ') << param_data.name.lexeme;
            if (param_data.type)
            {
              const auto &type_data = std::get<IdentifierNode>(param_data.type->data);
              std::cout << " " << type_data.name.lexeme;
            }
            std::cout << "\n";
          }
        }

        // Corpo (simples, só indica que existe por enquanto)
        if (func_data.body)
        {
          std::cout << std::string(indent + 6, ' ') << "Body: <block>\n";
          // Pode expandir pra imprimir o bloco depois
        }
      }
    }
  }

} // namespace debbuger
