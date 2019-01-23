#include "simple_parser/lexer.h"

#include "catch.hpp"

#include <fstream>
#include <iostream>

using namespace std;

TEST_CASE("Test Lexer works") {
  string filename = "tests/simple_source/assign.txt";
  ifstream input(filename);

  Simple::Lexer lexer = Simple::Lexer(input);

  for (auto& token: lexer.tokens) {
    std::cout << token->str() << std::endl;
  }

  REQUIRE(1 == 2);
}
