#include <iostream>
#include <string>
#include "hangman.h"
#include "evilhangman.h"

int main(){
  int wordLen = 0;
  int allowedGuesses = 5;

  std::cout << "Enter the word length: " << std::endl;
  std::cin >> wordLen;

  std::cout << "Enter the number of guesses allowed: " << std::endl;
  std::cin >> allowedGuesses;

  EvilHangman eh;
  eh.readDictionary("dictionary.txt");
  std::string word = eh.getRandomTargetWord(wordLen);
  eh = EvilHangman(allowedGuesses, wordLen, word);
  eh.readDictionary("dictionary.txt");
  eh.turn();
  return 0;
}