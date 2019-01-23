#include "simple_parser/lexer.h"
#include "simple_parser/parser.h"

#include "catch.hpp"

#include <fstream>
#include <iostream>

using namespace std;

TEST_CASE("Test Parser works") {
  string filename = "tests/simple_source/assign.txt";
  ifstream input(filename);

  Simple::Lexer lexer = Simple::Lexer(input);
  Simple::Parser parser = Simple::Parser(lexer.tokens);
  parser.parse();

  REQUIRE(1 == 2);
}
