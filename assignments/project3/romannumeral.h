#ifndef _romannumeral_h
#define _romannumeral_h

#include <string>
#include <unordered_map>

class Roman{
    private:
        std::unordered_map<char, int> romanNumDict;
        std::string romanNumKeys = "";
    
    public:
        Roman();
        int romanToDecimal(const std::string &str);
};
#endif