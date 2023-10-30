#include <iostream>
#include <string>
#include <unordered_map>
#include "romannumeral.h"

/*
     * Constructor: Roman
     * Usage: Roman rm
     * -------------------------------------
     * Initializes the unordered map containing the values for roman numerals
*/
Roman::Roman(){
    romanNumDict['I'] = 1;
    romanNumDict['V'] = 5;
    romanNumDict['X'] = 10;
    romanNumDict['L'] = 50;
    romanNumDict['C'] = 100;
    romanNumDict['D'] = 500;
    romanNumDict['M'] = 1000;
    romanNumKeys = "IVXLCDM";
}

/*
     * Methor: romanToDecimal
     * Usage: int num = rm.romanToDecimal(str)
     * -------------------------------------
     * Converts the given roman numeral into a decimal value.
*/
int Roman::romanToDecimal(const std::string &str){
    int result = 0;

    for(int i=0; i<str.length(); i++){
        if (romanNumKeys.find(str[i]) != std::string::npos) {
            int currRoman = romanNumDict[str[i]];
            int nextRoman = romanNumDict[str[i+1]];

            if(currRoman < nextRoman){
                result -= currRoman;
            }else{
                result += currRoman;
            }
        }else{
            result = -1;
            return result;
        }
        
    }
    return result;
}