#include <string>
#include <vector>
#include <iostream>

#include "token.h"

namespace Simple {
  class Node {
  public:
    Node* next = nullptr;
    Node() {};
    virtual std::string to_str() { return ""; };
  };

  class ProcedureNode : public Node {
  public:
    std::string procName;
    ProcedureNode(std::string name) : Node() {};
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

    bool check(Simple::TokenType type) {
      if (isAtEnd()) return false;
      return peek()->t = type;
    };

    Simple::BaseToken* advance() {
      if (!isAtEnd()) current++;
      return previous();
    };

    bool isAtEnd() {
      return peek()->t == Simple::TokenType::END_OF_FILE;
    };

    Simple::BaseToken* peek() {
      return tokens[current];
    };

    Simple::BaseToken* previous() {
      return tokens[current-1];
    };

    void parseProcedure () {
      if (!match(Simple::TokenType::PROCEDURE)) {
        std::cout << "WHAT";
      }

      if (!match(Simple::TokenType::SYMBOL)) {
        std::cout << "expecting a symbol"; // TODO: Handle errors properly
      }

      if (!match(Simple::TokenType::LBRACE)) {
        std::cout << "expecting a LBRACE"; // TODO: Handle errors properly
      }

      while (!match(Simple::TokenType::RBRACE)) {
        parseStatement();
      }
    };

    void parseStatement() {
      parseAssign();
    };

    void parseAssign() {
      int temp = current;
    };

  public:
    Parser(std::vector<Simple::BaseToken*> t) {
      tokens = t;
    }
    void parse() {
      parseProcedure();
    }
  };
}
