#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(std::string str);


int main(){

  std::string str_word = "";
  std::cout << "Enter the word to check for palindrome: ";
  std::cin >> str_word;

  
  return 0;
}


bool isPalindrome(std::string str){
  int len = str.length();
  if(len <= 1){
    return true;
  }else{
    return (str[0] == str[len - 1]) && (isPalindrome(str.substr(1, len-2));
  }

}
