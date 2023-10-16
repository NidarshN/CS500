#include "hangman.h"
#include "evilhangman.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <fstream>

EvilHangman::EvilHangman() : Hangman() {}

EvilHangman::EvilHangman(int allowedGuesses, int wordLength, std::string word): Hangman(allowedGuesses, wordLength, word){}

void EvilHangman::readDictionary(std::string fileName)
{
    std::ifstream file(fileName);
    if (file.is_open())
    {
        std::vector<std::string> words;
        std::string word;
        while (std::getline(file, word))
        {
            int wordLen = word.length();
            if (wordLen > 0)
            {
                wordCategory[wordLen].push_back(word);
            }
        }
    }
    else
    {
        std::cout << "Error: Unable to open file: " << fileName << std::endl;
    }
    file.close();
}

std::string EvilHangman::getRandomTargetWord(int wordLength)
{
    int indexBound = wordCategory[wordLength].size();
    srand(static_cast<unsigned int>(time(0)));
    int randomIndex = rand() % indexBound;
    return wordCategory[wordLength][randomIndex];
}

