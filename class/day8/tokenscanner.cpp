#include <cctype>
#include <string>
#include "tokenscanner.h"

TokenScanner::TokenScanner() {
}


TokenScanner::TokenScanner(std::string str){
  setInput(str);
}

void TokenScanner::setInput(std::string str){
  buffer = str;
  cp = 0;
}

bool TokenScanner::hasMoreTokens(){
  if(ignoreWhitespaceFlag) skipWhitespace();
  return cp < buffer.length();
}

std::string TokenScanner::nextToken(){
  if(ignoreWhitespaceFlag) skipWhitespace();
  if(cp >= buffer.length()){
    return "";
  }else if(isalnum(buffer[cp])){
    int start = cp;
    while(cp < buffer.length() && isalnum(buffer[cp])){
      cp++;
    }
    return buffer.substr(start, cp - start);
  }else {
    return std::string(1, buffer[cp++]);
  }
  
}

void TokenScanner::ignoreWhitespace(){
  ignoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace(){
  while(cp < buffer.length() && isspace(buffer[cp])){
    cp ++;
  }

}
