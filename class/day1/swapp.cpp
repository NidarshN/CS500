#include <iostream>

void swap(int &a,int  &b);

void swap(int &a,int  &b){
  int temp = a;
  a = b;
  b = temp;
}

int main(){
  int x, y;

  std::cout << "Enter the value for x: " << std::endl;
  std::cin >> x;
  std::cout << "Enter the value for y: " << std::endl;
  std::cin >> y;
  
  swap(x,y);

  std::cout << "x and y value after swap are: "
            << std::endl << "x: " << x << std::endl
            << "y: " << y << std::endl;
  return 0;
}
