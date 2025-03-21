#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <map>
#include <exception>

namespace core
{
  void printRed(const std::string &text);
  void printYellow(const std::string &text);
  std::runtime_error throw_program_error(const char *message);
} // namespace core

#endif // !CORE_H
