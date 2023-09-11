#ifndef _random_word_h
#define _random_word_h

#include <string>
#include <iostream>


static std::vector<std::string> dictionary;

void initDictionary(std::string file_name);

std::string chooseRandomWord();

#endif
