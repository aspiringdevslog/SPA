#include <iostream>
#include <string>
#include <vector>

#include "simple_parser/token.h"

namespace Simple {
class Node {
 public:
  Node* next = nullptr;
  Node(){};
  virtual std::string to_str() { return ""; };
};

class ProcedureNode : public Node {
 public:
  std::string procName;
  ProcedureNode(std::string name) : Node(){};
};

class Parser {
 private:
  int current = 0;
  std::vector<Simple::BaseToken*> tokens;
  Node* root = nullptr;

  bool match(Simple::TokenType type) {
    if (check(type)) {
      advance();
      return true;
    } else {
      return false;
    }
  };

  bool expect(Simple::TokenType type) {
    if (match(type)) {
      return true;
    } else {
      // TODO: Handle this better
      std::cout << peek()->str() << std::endl;
      std::cout << "expected a different symbol." << std::endl;
      return false;
    }
  };

  bool check(Simple::TokenType type) {
    if (isAtEnd()) return false;
    return peek()->t == type;
  };

  Simple::BaseToken* advance() {
    if (!isAtEnd()) current++;
    return previous();
  };

  bool isAtEnd() { return peek()->t == Simple::TokenType::END_OF_FILE; };

  Simple::BaseToken* peek() { return tokens[current]; };

  Simple::BaseToken* previous() { return tokens[current - 1]; };

  void parseProcedure() {
    if (match(Simple::TokenType::PROCEDURE)) {
      expect(Simple::TokenType::SYMBOL);
      expect(Simple::TokenType::L_BRACE);
      parseStatementList();
      expect(Simple::TokenType::R_BRACE);
    } else {
      std::cout << "procedure: syntax error";
    }
  };

  void parseStatementList() { parseStatement(); }

  void parseStatement() { parseAssign(); };

  void parseAssign() {
    expect(Simple::TokenType::SYMBOL);
    expect(Simple::TokenType::EQUAL);
    expect(Simple::TokenType::NUMBER);
    expect(Simple::TokenType::SEMI);
  };

 public:
  Parser(std::vector<Simple::BaseToken*> t) { tokens = t; }
  void parse() { parseProcedure(); }
};
}  // namespace Simple
