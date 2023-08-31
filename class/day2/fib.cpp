#include <iostream>
#include <string>

int fibonacci(int n);

int main(){
  std::string s;
  int i;
  
  std::cout << "Enter a Number:";
  std::cin >> s;
  i = stoi(s);

  
  std::cout << fibonacci(i) << '\n';
}

int fibonacci(int n){
  if(n == 0)
    return 0;
  if(n == 1)
    return 1;
  return fibonacci(n-1) + fibonacci(n-2);
}
