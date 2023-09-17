#include <iostream>
#include <string>

bool startsWith(std::string str, std::string prefix){
  return str.find(prefix, 0);

}

int main(){
  std::string str = "hello";
  std::string prefix = "hell";
  if(startsWith(str, prefix) == 0){
    std::cout << "Starts With" << std::endl;
  }
  return 0;
}
