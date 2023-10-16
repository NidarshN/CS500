#ifndef _evilhangman_h
#define _evilhangman_h

#include <string>
#include <vector>
#include <map>
#include "hangman.h"

class EvilHangman : public Hangman {
    private:
        std::vector<std::string>wordList;
        std::map<int, std::vector<std::string>> wordCategory;
        std::map<std::string, std::vector<std::string>> wordFamily;

    public:
        EvilHangman();
        EvilHangman(int allowedGuesses, int wordLength, std::string word);

        void readDictionary(std::string fileName);
        std::string getRandomTargetWord(int wordLength);
        void updateBoard(char guess);

};

#endif