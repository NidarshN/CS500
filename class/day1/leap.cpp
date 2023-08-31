#include <iostream>

bool evalLeap(int year);

bool evalLeap(int year){
  return ((year % 4 == 0 && year % 100 != 0)) || (year % 400 == 0);
}

int main(){

  int year;
  int result = 0;
  
  std::cout << "Enter a year: ";
  std::cin >> year;
  result = evalLeap(year);
  
  std::cout << "Result: " <<result;
  return 0;

}
