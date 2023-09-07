#include <iostream>
#include <cmath>
#include <ctime>
#include <limits.h>
#include "custom_random.h"


void initRandomSeed(){
  static bool initialized = false;
  if(!initialized){
    srand(time(NULL));
    initialized = true;
  }
}

void setRandomSeed(int seed){
  initRandomSeed();
  srand(seed);
}

//int randomInteger();

int randomInteger(int low, int high){
  initRandomSeed();
  double rand_num = double(low) + (rand() % (high - low));
  return int(floor(rand_num));
}

//double randomReal();

double randomReal(double low, double high){
  initRandomSeed();
  
  double rand_num = 1.0;
  //rand_num *=  double (low + (rand() % int(high - low))) * 200.0;
  double offset = (high - low) * (((double) rand()) / RAND_MAX);

  rand_num *= offset;

  return rand_num ;
}

bool randomChance(double probability){
  initRandomSeed();
  return randomReal(0, 1) < probability;
}
