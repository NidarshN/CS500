#include "emailValidator.h"
#include <iostream>
#include <regex>
#include <string>

bool emailValidator(std::string email){
  std::regex emailReg(R"([a-zA-Z0-9]{1,20}\.[!$&a-zA-Z]+@[a-z]{1,20}\.[a-z]{1,3})");

  if (std::regex_match(email, emailReg)) {
        if (email.find(' ') != std::string::npos) {
            return false; 
        }
        return true;
    } else {
        return false;
    }
}
