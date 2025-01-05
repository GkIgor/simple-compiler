#include "frontend/lexer/lexer.h"

namespace frontend {
namespace lexer {
Tokenize::Tokenize(std::string &filename) {
  file.open(filename);
  if (file.is_open()) {
    Tokenize::read_lines();
  }
}

Tokenize::~Tokenize() {
  if (file.is_open()) {
    file.close();
  }
}

void Tokenize::read_lines() {
  std::string line{};
  if (file.is_open()) {
    while (std::getline(file, line) && !file.eof()) {
      std::cout << line << std::endl;
    }
  }
}
} // namespace lexer
} // namespace frontend
