#include <iostream>
#include <string>

std::string reverseString(std::string str){
  std::string rev_str = "";
  int n = str.length();
  for(int i = n - 1; i >= 0; --i){
    rev_str += str[i];
  }
  
  return rev_str;
}
int main(){
  std::string str;
  std::cout << "Enter the string to be reversed: " << std::endl;
  std::cin >> str;
  std::cout << reverseString(str);
  return 0;
}
