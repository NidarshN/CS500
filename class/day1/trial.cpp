#include <iostream>

int main(){
  std::cout << 2+3<<"\n";
  std::cout<< 3 * 6.0 <<"\n";
  std::cout << 19 / 5 << "\n";
  std::cout <<19%5<<"\n";
  std::cout <<19.0/5<<"\n";
  std::cout <<2%7<<"\n";


  std::cout <<"--------\n";
  int a = 5;
  int b = a++; 
  std::cout << "a: " << a << "\n"; 
  std::cout << "b: " << b << "\n";


  std::cout <<"--------\n";
  a = 5; 
  b = ++a; 
  std::cout << "a: " << a << "\n"; 
  std::cout << "b: " << b << "\n";

  return 0;
}
