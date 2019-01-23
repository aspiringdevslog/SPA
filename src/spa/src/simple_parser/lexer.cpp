#include <vector>
#include <iostream>
#include <string>
#include <cctype>

#include "token.h"
#include "lexer.h"

void getSymbol(std::istream& stream, std::string& str) {
  while (isalnum(stream.peek())) {
    str += stream.get();
  }
}

void getNumber(std::istream& stream, std::string& str) {
  while (isdigit(stream.peek())) {
    str += stream.get();
  }
}

Simple::Lexer::Lexer(std::istream& stream) {
  char nextChar;
  std::string str;

  while (!stream.eof()) {
    nextChar = stream.get();
    str += nextChar;
    if (isalpha(nextChar)) { // Reserved keyword or variable
      getSymbol(stream, str);
      if (str.compare("procedure") == 0) {
        tokens.push_back(new Simple::ProcedureToken());
      } else {
        tokens.push_back(new Simple::SymbolToken(str));
      }
    } else if (isdigit(nextChar)) { // Numbers
      getNumber(stream, str);
      tokens.push_back(new Simple::NumberToken(str));
    } else if (nextChar  == '{') {
      tokens.push_back(new Simple::LBraceToken());
    } else if (nextChar  == '}') {
      tokens.push_back(new Simple::RBraceToken());
    } else if (nextChar == '=') {
      tokens.push_back(new Simple::EqualToken());
    } else if (nextChar == ';') {
      tokens.push_back(new Simple::SemiToken());
    } else if (nextChar == '\n') {
      tokens.push_back(new Simple::EOLToken());
    } else if (iswspace(nextChar)) { // Ignore whitespaces
      ;
    } else {
      std::cout << nextChar; // TODO: Properly handle error
    }
    str = "";
  }
  tokens.push_back(new Simple::EOFToken());
};
