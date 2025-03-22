#ifndef PARSER_H
#define PARSER_H

#include <variant>
#include "frontend/lexer/lexer.h"
#include "frontend/lexer/keywords.h"
#include "frontend/utils/utils.hpp"
#include "core/core.hpp"

struct Node;

enum class NodeType
{
  PROGRAM,              // Nó raiz do programa
  CLASS_DECLARATION,    // Declaração de classe (ex.: CLASS Pessoa)
  FUNCTION_DECLARATION, // Declaração de função (ex.: FN new)
  BLOCK,                // Bloco de código ({ ... })
  VARIABLE_DECLARATION, // Declaração de variável (ex.: VAR pessoa)
  ASSIGNMENT,           // Atribuição (ex.: this.nome = nome)
  FUNCTION_CALL,        // Chamada de função (ex.: PRINT("..."))
  BINARY_OPERATION,     // Operação binária (ex.: idade + 1)
  IF_STATEMENT,         // Condicional (ex.: IF ... {...})
  FOR_STATEMENT,        // Laço for (ex.: FOR i IN 1..10)
  WHILE_STATEMENT,      // Laço while (ex.: WHILE ...)
  RETURN_STATEMENT,     // Retorno (ex.: return ...)
  LITERAL,              // Literal (ex.: "João", 25)
  IDENTIFIER,           // Identificador (ex.: nome, idade)
  UNKNOWN               // Para erros ou tipos não identificados
};

struct ProgramNode
{
  std::string target_os;
  std::string target_arch;
  std::vector<Node *> declarations;
};

// Declaração de classe
struct ClassDeclarationNode
{
  Token name;                  // ex.: "Pessoa"
  std::vector<Node *> members; // Variáveis (nome TEXT, idade INT)
  std::vector<Node *> methods; // Funções (ex.: new, getInfo)
};

// Declaração de função
struct FunctionDeclarationNode
{
  Token name;                     // ex.: "new", "main"
  std::vector<Node *> parameters; // ex.: nome TEXT, idade INT
  Node *body;                     // Bloco de código
};

// Bloco de código
struct BlockNode
{
  std::vector<Node *> statements; // Lista de instruções
};

// Declaração de variável
struct VariableDeclarationNode
{
  Token name;        // ex.: "pessoa"
  Node *type;        // ex.: TEXT, INT (opcional, pode ser nullptr)
  Node *initializer; // ex.: NEW Pessoa("João", 25)
};

// Atribuição
struct AssignmentNode
{
  Node *target; // ex.: this.nome
  Node *value;  // ex.: nome
};

// Chamada de função
struct FunctionCallNode
{
  Token name;                    // ex.: "PRINT", "NEW"
  std::vector<Node *> arguments; // ex.: "Maior de idade"
};

// Operação binária
struct BinaryOperationNode
{
  Token op;    // ex.: "+", "||"
  Node *left;  // ex.: idade
  Node *right; // ex.: 1
};

// Condicional
struct IfStatementNode
{
  Node *condition;   // ex.: pessoa.idade > 18
  Node *then_branch; // Bloco do IF
  Node *else_branch; // Bloco do ELSE (pode ser nullptr)
};

// Laço FOR
struct ForStatementNode
{
  Token iterator;    // ex.: "i"
  Node *range_start; // ex.: 1
  Node *range_end;   // ex.: 10
  Node *body;        // Bloco do FOR
};

// Laço WHILE
struct WhileStatementNode
{
  Node *condition; // ex.: contador < 5
  Node *body;      // Bloco do WHILE
};

// Retorno
struct ReturnStatementNode
{
  Node *expression; // ex.: nome || ' tem ' || idade
};

// Literal
struct LiteralNode
{
  Token value; // ex.: "João", 25
};

// Identificador
struct IdentifierNode
{
  Token name; // ex.: "nome", "idade"
};

// Estrutura principal do nó usando std::variant
struct Node
{
  NodeType type;
  std::variant<
      ProgramNode,
      ClassDeclarationNode,
      FunctionDeclarationNode,
      BlockNode,
      VariableDeclarationNode,
      AssignmentNode,
      FunctionCallNode,
      BinaryOperationNode,
      IfStatementNode,
      ForStatementNode,
      WhileStatementNode,
      ReturnStatementNode,
      LiteralNode,
      IdentifierNode>
      data;

  Node(NodeType t) : type(t) {}

  template <typename T>
  Node(NodeType t, T &&value) : type(t), data(std::forward<T>(value)) {}
};

namespace frontend
{
  namespace parser
  {
    extern const Token empty_token;

    class Parser
    {
    private:
      std::vector<Token> tokens; // Tokens recebidos do lexer
      size_t current_pos;        // Posição atual no vetor de tokens
      Node *root;                // Nó raiz da AST
      std::map<std::string, std::string> get_current_os();

    public:
      explicit Parser(const std::vector<Token> &tokens);
      ~Parser();

      Node *parse();

      Node *parse_program();
      Node *parse_class_declaration();
      Node *parse_function_declaration();
      Node *parse_block();
      Node *parse_variable_declaration();
      Node *parse_assignment();
      Node *parse_function_call();
      Node *parse_binary_operation();
      Node *parse_if_statement();
      Node *parse_for_statement();
      Node *parse_while_statement();
      Node *parse_return_statement();
      Node *parse_literal();
      Node *parse_identifier();

      Token current_token() const;              // Olha o Token Atual
      Token peek() const;                       // Olha o proximo Token
      void advance();                           // Avanca para o proximo token
      bool match(const std::string &lexeme);    // Verifica se o token atual tem o lexema esperado, se sim, avança para o próximo token.
      bool match_type(const std::string &type); // Verifica se o token atual tem o tipo esperado, se sim, avança para o próximo token.
      void expect(const std::string &lexeme);   // Verifica se o token atual tem o lexema esperado e avança

      Node *getRoot() const; // Retorna a o nó da raiz
    }; // Class Parser

    Parser *start_parse(const std::vector<Token> &tokens);
  } // namespace parser

} // namespace frontend

#endif // PARSER_H