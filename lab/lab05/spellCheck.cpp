#include <iostream>
#include <regex>
#include "spellCheck.h"
#include <cctype>
#include <string>

std::string spellCheck(std::string recLetter, std::string studentName){

  std::string initialLetters = studentName.substr(0, 4);

  std::regex namePattern("\\b(" + initialLetters + ")[a-z]*\\b", std::regex_constants::icase);
  std::string corrected_recLetter = std::regex_replace(recLetter, namePattern, studentName);

  return corrected_recLetter;

}
