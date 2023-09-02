#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout << "Please enter your name: ";
  std::getline(std::cin, s);
  std::cout << "Hello " << s << std::endl;
  std::cout << "Have fun learning c++!" << std::endl;
  return 0;
}
