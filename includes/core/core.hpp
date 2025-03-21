#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <map>
#include <exception>
#include <string>

namespace core
{
  void printRed(const char *text);
  void printYellow(const char *text);
  std::runtime_error throw_program_error(const char *message);
} // namespace core

#endif // !CORE_H
