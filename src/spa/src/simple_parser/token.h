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
  private:
    TokenType t;
  public:
    BaseToken(TokenType token_t) {
      t = token_t;
    }
    virtual std::string str(){ return "BaseToken"; };
  };

  class ProcedureToken: public BaseToken {
  private:
    std::string name;
  public:
    ProcedureToken() : BaseToken(TokenType::PROCEDURE) {};
    std::string str() {
      return "PROCEDURE[]";
    };
  };

  class SymbolToken: public BaseToken {
  private:
    std::string name;
  public:
    SymbolToken(std::string n) : BaseToken(TokenType::SYMBOL) {
      name = n;
    };
    std::string str() {
      return "SYMBOL[" + name + "]";
    };
  };

  class NumberToken: public BaseToken {
  private:
    std::string number;
  public:
    NumberToken(std::string n) : BaseToken(TokenType::NUMBER) {
      number = n;
    };
    std::string str() {
      return "NUMBER[" + number + "]";
    };
  };

  class EOLToken: public BaseToken {
  public:
    EOLToken() : BaseToken(TokenType::EOL) {};
    std::string str() {
      return "EOL[]";
    };
  };

  class LBraceToken: public BaseToken {
  public:
    LBraceToken() : BaseToken(TokenType::L_BRACE) {};
    std::string str() {
      return "LBRACE[]";
    };
  };

  class RBraceToken: public BaseToken {
  public:
    RBraceToken() : BaseToken(TokenType::R_BRACE) {};
    std::string str() {
      return "RBRACE[]";
    };
  };

  class EqualToken: public BaseToken {
  public:
    EqualToken() : BaseToken(TokenType::EQUAL) {};
    std::string str() {
      return "EQUAL[]";
    };
  };

  class SemiToken: public BaseToken {
  public:
    SemiToken() : BaseToken(TokenType::SEMI) {};
    std::string str() {
      return "SEMI[]";
    };
  };

  class EOFToken: public BaseToken {
  public:
    EOFToken() : BaseToken(TokenType::END_OF_FILE) {};
    std::string str() {
      return "EOF[]";
    };
  };
}

#endif
