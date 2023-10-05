#include <iostream>
#include "emailValidator.h"

int main() {
    std::string email1 = "joe.Mack@gmail.com";
    std::string email2 = "Henry1999.Tuttle!@uab.edu";
    std::string email3 = "jasonIsTheCoolestManEver.Horatio Nelson@Outlook.edu";
    std::string email4 = "abcd&nnithyan.N@uab.edu";

    if (emailValidator(email1)) {
        std::cout << "Email 1 is valid." << std::endl;
    } else {
        std::cout << "Email 1 is not valid." << std::endl;
    }

    if (emailValidator(email2)) {
        std::cout << "Email 2 is valid." << std::endl;
    } else {
        std::cout << "Email 2 is not valid." << std::endl;
    }

    if (emailValidator(email4)) {
        std::cout << "Email 4 is valid." << std::endl;
    } else {
        std::cout << "Email 4 is not valid." << std::endl;
    }

    return 0;
}
