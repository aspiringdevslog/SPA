#include <string>

enum TokenType {
                NUMBER, SYMBOL,

                // Reserved keywords
                PROCEDURE,

                // Punctuation
                L_BRACE, R_BRACE,
};

class Token {
private:
  TokenType t;
  std::string str;
public:
  Token(TokenType token_t) {
    t = token_t;
  }
};
