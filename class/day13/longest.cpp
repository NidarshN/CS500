#include <fstream>
#include <iostream>
#include <string>

int main(){
    std::ifstream file("myFile.txt");

    std::string longest_line = "";

    std::string line = "";

    while (std::getline(file, line)) {
        if (line.length() >= longest_line.length()) {
            longest_line = line;
        }
    }

    std::cout << longest_line << std::endl;

    file.close();


    return 0;
}