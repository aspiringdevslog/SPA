#include "lexer.h"

#include "catch.hpp"

#include <fstream>

using namespace std;

TEST_CASE("Test Lexer works") {
  string filename = "tests/simple_source/assign.txt";
  ifstream input(filename);

  Lexer lexer = Lexer(input);

  REQUIRE(1 == 2);
}
