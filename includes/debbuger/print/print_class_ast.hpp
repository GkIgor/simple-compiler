#ifndef DEBUGGER_HPP
#define DEBUGGER_HPP

#include "frontend/parser/parser.h"

namespace debugger
{
  void print_class_ast(const Node *node, int indent = 0);
} // namespace debugger

#endif // DEBUGGER_HPP