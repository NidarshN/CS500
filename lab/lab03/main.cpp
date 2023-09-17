#include <iostream>
#include <vector>
#include "trip.h"


int main(){

  std::vector<float> expenses = {15.00f, 15.01f, 3.00f, 3.01f};

  std::cout << "Money: " << moneyEqualizer(expenses);
  return 0;
}
