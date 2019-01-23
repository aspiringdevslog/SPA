#ifndef __LEXER_H
#define __LEXER_H

#include <fstream>
#include <vector>

#include "token.h"

class Lexer {
 public:
  std::vector<Token> tokens;
  Lexer(std::istream& stream);
};
#endif
