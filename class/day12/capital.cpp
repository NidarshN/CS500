#include <iostream>
#include <string>

std::string capitalize(std::string str){
    str[0] -= 32;
    return str;
}


int main(){
    std::string str = "";
    std::cout << "Enter a string: "<< std::endl;
    std::getline(std::cin, str);
    std::cout << "String: " << capitalize(str) << std::endl;
    return 0;
}