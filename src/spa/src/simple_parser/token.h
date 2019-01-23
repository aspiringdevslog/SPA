#ifndef __SIMPLE_TOKEN_H
#define __SIMPLE_TOKEN_H
#include <string>

namespace Simple {
  enum TokenType {
                  NUMBER, SYMBOL,

                  // Reserved keywords
                  PROCEDURE,

                  EQUAL,

                  // Punctuation
                  L_BRACE, R_BRACE, EOL, END_OF_FILE, SEMI
  };

  class BaseToken {
  public:
    int row;
    TokenType t;
    BaseToken(int r, TokenType token_t) {
      row = r;
      t = token_t;
    }
    virtual std::string str() = 0;
  };

  class ProcedureToken: public BaseToken {
  private:
    std::string name;
  public:
    ProcedureToken(int r) : BaseToken(r, TokenType::PROCEDURE) {};
    std::string str() {
      return "PROCEDURE[row=" + std::to_string(row) + "]";
    };
  };

  class SymbolToken: public BaseToken {
  private:
    std::string name;
  public:
    SymbolToken(int r, std::string n) : BaseToken(r, TokenType::SYMBOL) {
      name = n;
    };
    std::string str() {
      return "SYMBOL[row=" + std::to_string(row) + ",name=" + name + "]";
    };
  };

  class NumberToken: public BaseToken {
  private:
    std::string number;
  public:
    NumberToken(int r, std::string n) : BaseToken(r, TokenType::NUMBER) {
      number = n;
    };
    std::string str() {
      return "NUMBER[row=" + std::to_string(row) + ",num=" + number + "]";
    };
  };

  class LBraceToken: public BaseToken {
  public:
    LBraceToken(int r) : BaseToken(r, TokenType::L_BRACE) {};
    std::string str() {
      return "LBRACE[row=" + std::to_string(row) + "]";
    };
  };

  class RBraceToken: public BaseToken {
  public:
    RBraceToken(int r) : BaseToken(r, TokenType::R_BRACE) {};
    std::string str() {
      return "LBRACE[row=" + std::to_string(row) + "]";
    };
  };

  class EqualToken: public BaseToken {
  public:
    EqualToken(int r) : BaseToken(r, TokenType::EQUAL) {};
    std::string str() {
      return "EQUAL[row=" + std::to_string(row) + "]";
    };
  };

  class SemiToken: public BaseToken {
  public:
    SemiToken(int r) : BaseToken(r, TokenType::SEMI) {};
    std::string str() {
      return "SEMI[row=" + std::to_string(row) + "]";
    };
  };

  class EOFToken: public BaseToken {
  public:
    EOFToken(int r) : BaseToken(r, TokenType::END_OF_FILE) {};
    std::string str() {
      return "EOF[row=" + std::to_string(row) + "]";
    };
  };
}

#endif
