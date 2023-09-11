#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include "randword.h"

void displayWelcome();


void initGame(std::string secret_word);

int main(){
  initDictionary("wordlist.txt");
  displayWelcome();
  
  std::string secret_word = chooseRandomWord();
  
  std::cout << secret_word << std::endl;

  initGame(secret_word);

  return 0;
}


void displayWelcome(){
  std::cout << "Welcome to the Hangman Game!" << std::endl << std::endl;
  std::cout << "The game will select a secret word. You should guess a letter at each turn." << std::endl
            << "If the letter appears in the secret word, then it will show all the occurence of the letter in the secret word where it appears." << std::endl
            << "If you fail to guess the correct letter at each turn, a part of your body gets strung up on the scaffold." << std::endl
            << "After 5 turns, if you have not guessed the secret word, you will be hung!" << std::endl << std::endl;

  std::cout << "All the best! The game begins!"  << std::endl << std::endl;
}


void initGame(std::string secret_word){
  int word_len = secret_word.size();
  int turns = 5;
  bool isMatch = false;
  
  std::string temp_word;

  for(int i=0; i < word_len; ++i){
    temp_word += '-';
  }
  std::cout << "Actual Word: " << secret_word << std::endl
            << "Masked Word: " << temp_word;

  while(!isMatch && turns > 0){
    char ch;
    bool isFound = false;
    std::cout << std::endl;
    std::cout << "The Secret Word: " << temp_word << std::endl;
    std::cout << "You have " << turns << " guesses left!" << std::endl;

    std::cout << std::endl;

    std::cout << "Guess a letter: ";
    std::cin >> ch;

    if(!((temp_word.find(std::tolower(ch)) != std::string::npos) || (temp_word.find(std::toupper(ch)) != std::string::npos))){
      for(int i=0; i < word_len; ++i){
      
	if(std::tolower(secret_word[i]) == std::tolower(ch)){
	    temp_word[i] = secret_word[i];
	    isFound = true;
        }

      }
    }else{
	std::cout << ch << " Character already guessed!" << std::endl;
	continue;
    }


    if(!isFound){
      --turns;
    }

    if(secret_word.compare(temp_word) == 0){
      isMatch = true;
    }
  }

  std::cout << std::endl;
  
  if(isMatch){
    std::cout << "Congratulations! You won!" << std::endl;
  }else{
    std::cout << "Better luck in your next life!" << std::endl;
  }
}
