#include <iostream>
#include <string> 
#include <algorithm>
#include "romannumeral.h"

int main(){
    std::string romanInput = "";
    Roman rd;
    std::cout << "Enter the Roman Numeral you wish to translate to Number:" << std::endl;
    std::cin >> romanInput;
    std::transform(romanInput.begin(), romanInput.end(), romanInput.begin(), ::toupper);
    int result = rd.romanToDecimal(romanInput);
    if(result != -1){
        std::cout << "Translated Roman Numeral: " << result << std::endl;
    }else{
        std::cout << "Invalid Input for Roman Numerals!" << std::endl;
    }
}