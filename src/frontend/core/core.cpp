#include "core/core.hpp"

namespace core
{
  void printRed(const char *text)
  {
    std::cout << "\033[31m" << text << "\033[0m"; // 31: vermelho
  }

  void printYellow(const char *text)
  {
    std::cout << "\033[33m" << text << "\033[0m"; // 33: amarelo
  }

  std::runtime_error throw_program_error(const char *message)
  {
    return std::runtime_error(message);
  }
} // namespace core