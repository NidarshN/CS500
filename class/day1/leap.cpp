#include <iostream>

bool evalLeap(int year);

/**
   Function to evaluate a year is leap or not.

   Parameters
   ==========
   year (int) : User input year.

   Returns
   =======
   (bool) : returns true if the year is leap else false.
 */

bool evalLeap(int year){
  return ((year % 4 == 0 && year % 100 != 0)) || (year % 400 == 0);
}

int main(){

  int year;
  int result = 0;
  
  std::cout << "Enter a year: ";
  std::cin >> year;
  result = evalLeap(year);

  if(result == 1)
    std::cout << "Result: " << year << " is a leap year" << std::endl;
  else
    std::cout << "Result: " << year << " is not a leap year" << std::endl;
  
  return 0;

}
