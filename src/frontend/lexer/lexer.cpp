#include "frontend/lexer/lexer.h"

namespace frontend {
namespace lexer {
void start_analize_lexical(std::string &filename) {
  Tokenize tokenizer(filename);
}
} // namespace lexer
} // namespace frontend
