#include <vector>
#include <iostream>
#include <string>
#include <cctype>

#include "lexer.h"

std::string getSymbol(std::istream& stream) {
  std::string s;
  while (isalpha(stream.peek())) {
    s += stream.get();
  }
  return s;
}

std::string getNumber(std::istream& stream) {
  std::string s;
  while (isdigit(stream.peek())) {
    s += stream.get();
  }
  return s;
}

Lexer::Lexer(std::istream& stream) {
  char nextChar;

  while (!stream.eof()) {
    nextChar = stream.peek();
    if (isalpha(nextChar)) { // Reserved keyword or variable
      std::string symbol = getSymbol(stream);
      std::cout << symbol << std::endl;
    } else if (isdigit(nextChar)) { // Numbers
      std::string number = getNumber(stream);
      std::cout << number << std::endl;
    } else {
      switch (nextChar) {
      default:
        stream.get();
        break;
      }
    }
  }
};
