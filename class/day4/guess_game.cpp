#include <iostream>
#include <string>
#include "custom_random.h"

int main(){
  int rounds_num = 0, user_score = 0, low = 0, high = 0;
  std::cout << "Welcome to the Guessing Game" << std::endl;
  std::cout << "Enter the number of rounds you want to play: " << std::endl;
  std::cin >> rounds_num;
  std::cout << "Enter the minimum range bound: " << std::endl;
  std::cin >> low;
  std::cout << "Enter the maximum range bound: " << std::endl;
  std::cin >> high;
  
  for(int i = 0; i < rounds_num; i++){
    std::cout << std::endl << std::endl
              << "ROUND " << i + 1 << std::endl << std::endl;
    int num = randomInteger(low, high), user_num = 0;
    std::cout << "Guess a number between (" << low << ","
	      << high << "): " << std::endl;
    std::cin>> user_num;

    std::cout << "Generated Number is " << num << std::endl;
    if(user_num == num){
      std::cout << "Congratulation: you have guessed right!" << std::endl;
      user_score += 1;
      std::cout << "Your Score: " << user_score << std::endl;
    }else{
      std::cout << "Better luck next time!" << std::endl;
    }
      
  }
  return 0;
}
