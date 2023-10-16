#include "hangman.h"
#include <iostream>
#include <algorithm>
#include <string>

Hangman::Hangman(){
  numberOfAllowedGuesses = 5;
  numberOfGuesses = 0;

  targetWord = "Hello";
  lengthOfWord = targetWord.length();

  for(int i=0; i < lengthOfWord;i++){
    displayString += '_';
  }
}

Hangman::Hangman(int allowedGuesses, int wordLength, std::string word){
  lengthOfWord = wordLength;
  numberOfAllowedGuesses = allowedGuesses;
  displayString = "";
  numberOfGuesses = 0;
  targetWord = word;

  for(int i=0; i < wordLength; i++){
    displayString += '_';
  }
}


void Hangman::displayBoard(){
  std::cout << displayString << std::endl;
  std::cout << "Guesses Left: " << (numberOfAllowedGuesses - numberOfGuesses) << std::endl;
}

void Hangman::updateBoard(char guess){
  bool flag = false;
  if(checkGuessExceeded()){
    std::cout << "Sorry! You Lost: ran out of number of guesses!" << std::endl;
    return;
  }

  for(int i = 0; i < targetWord.length(); i++){
    if(guess == targetWord[i]){
      flag = true;
      displayString[i] = guess;
    }
  }
  if(!flag){
    std::cout << "Sorry! " << guess << " was an incorrect guess!" << std::endl;
  }
  ++numberOfGuesses;
  return;
}

bool Hangman::checkWord(){
  return (targetWord.compare(displayString) == 0);
}

bool Hangman::checkGuessExceeded(){
  if(numberOfAllowedGuesses <= numberOfGuesses){
    return true;
  }else{
    return false;
  }
}

void Hangman::handleInput(){
  while(true){
    char input;
    std::cout << "Enter your guess: ";
    std::cin >> input;
    input = tolower(input);
    if(std::find(guessedLetters.begin(), guessedLetters.end(), input) == guessedLetters.end()){
      updateBoard(input);
      guessedLetters.push_back(input);
      break;
    }else{
      std::cout << "Already guessed this character: " << input << " ! Try Again !" << std::endl;
    }
  }
}

void Hangman::setTargetWord(std::string word){
  targetWord = word;
}

std::string Hangman::getTargetWord()
{
  return targetWord;
}

void Hangman::setDisplayString(std::string str)
{
  displayString = str;
}

std::string Hangman::getDisplayString()
{
  return displayString;
}

void Hangman::incrementGuess()
{
  ++numberOfGuesses;
}

void Hangman::unitTest(){
    std::cout << displayString << std::endl;
}

void Hangman::turn(){
  int gameFlag = false;
  while(!gameFlag){
    displayBoard();
    handleInput();
    gameFlag = checkWord() || checkGuessExceeded();
    if(gameFlag && checkWord()){
      std::cout << "Congratulations! You won!" << std::endl;
    }else if(gameFlag && checkGuessExceeded()){
      std::cout << "You Lost: ran out of guesses!" << std::endl;
    }
  }
}



