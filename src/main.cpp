#include "frontend/lexer/lexer.h"
#include <iostream>

void printRed(const std::string &text) {
  std::cout << "\033[31m" << text << "\033[0m"; // 31: vermelho
}

void printYellow(const std::string &text) {
  std::cout << "\033[33m" << text << "\033[0m"; // 33: amarelo
}

int main(int argc, char *argv[]) {
  std::string path_name{};

  if (argc >= 2) {
    path_name = argv[argc - 1];
  } else {
    printRed("Error:\n No file selected!\n");
  }

  frontend::lexer::start_analize_lexical(path_name);

  return 0;
}
