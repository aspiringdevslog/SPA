#ifndef __SIMPLE_LEXER_H
#define __SIMPLE_LEXER_H

#include <fstream>
#include <vector>

#include "token.h"
namespace Simple {
  class Lexer {
  public:
    std::vector<BaseToken*> tokens;
    Lexer(std::istream& stream);
  };
}
#endif
