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
  int row = 1;

  while (!stream.eof()) {
    nextChar = stream.get();
    str += nextChar;
    if (isalpha(nextChar)) { // Reserved keyword or variable
      getSymbol(stream, str);
      if (str.compare("procedure") == 0) {
        tokens.push_back(new Simple::ProcedureToken(row));
      } else {
        tokens.push_back(new Simple::SymbolToken(row, str));
      }
    } else if (isdigit(nextChar)) { // Numbers
      getNumber(stream, str);
      tokens.push_back(new Simple::NumberToken(row, str));
    } else if (nextChar  == '{') {
      tokens.push_back(new Simple::LBraceToken(row));
    } else if (nextChar  == '}') {
      tokens.push_back(new Simple::RBraceToken(row));
    } else if (nextChar == '=') {
      tokens.push_back(new Simple::EqualToken(row));
    } else if (nextChar == ';') {
      tokens.push_back(new Simple::SemiToken(row));
    } else if (nextChar == '\n') {
      row++;
    } else if (iswspace(nextChar)) { // Ignore whitespaces
      ;
    } else {
      std::cout << nextChar; // TODO: Properly handle error
    }
    str = "";
  }
  tokens.push_back(new Simple::EOFToken(row));
};
