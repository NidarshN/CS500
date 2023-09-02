#include <iostream>

int main(){
  std::cout << 2+3 << std::endl;
  std::cout<< 3 * 6.0 << std::endl;
  std::cout << 19 / 5 << std::endl;
  std::cout <<19 % 5 << std::endl;
  std::cout <<19.0 / 5 << std::endl;
  std::cout <<2 % 7 << std::endl;


  std::cout << "--------" << std::endl;
  
  int a = 5;
  int b = a++; 
  std::cout << "a: " << a << std::endl; 
  std::cout << "b: " << b << std::endl;


  std::cout << "--------" << std::endl;
  
  a = 5; 
  b = ++a; 
  std::cout << "a: " << a << std::endl; 
  std::cout << "b: " << b << std::endl;

  return 0;
}
