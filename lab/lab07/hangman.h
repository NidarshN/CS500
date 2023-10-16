#ifndef _hangman_h
#define _hangman_h

#include <string>

class Hangman
{
  private:
  int numberOfGuesses;
  int numberOfAllowedGuesses;
  int lengthOfWord;

  std::string targetWord;
  std::string displayString;
  std::vector<char> guessedLetters;

public:
  Hangman();
  Hangman(int allowedGuesses, int wordLength, std::string word);
  void displayBoard();
  void updateBoard(char guess);
  bool checkWord();
  bool checkGuessExceeded();
  void handleInput();
  
  void setTargetWord(std::string word);
  std::string getTargetWord();

  void setDisplayString(std::string str);
  std::string getDisplayString();
  void incrementGuess();
  //~Hangman();
  void unitTest();
  void turn();

  

};
#endif
