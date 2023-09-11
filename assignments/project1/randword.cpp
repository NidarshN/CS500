#include <iostream>
#include <string>
#include <fstream>
#include "randword.h"

//static std::vector<std::string> dictionary;

void initDictionary(std::string file_name){
  std::ifstream dataFile (file_name);
  std::string word;

  if(dataFile.is_open()){
    while(dataFile){
      std::getline(dataFile, word);
      if(!word.empty()){
	dictionary.push_back(word);
      }
    }
  }
}



std::string chooseRandomWord(){
  srand(time(NULL));
  int dict_size = dictionary.size();
  int ind = rand() % dict_size;
  return dictionary[ind];
}
