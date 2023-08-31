#include <iostream>

void swap(int &a,int  &b);

void swap(int &a,int  &b){
  int *temp = &a;
  *a = *b;
  *b = *temp;
  std::cout<<a<<b;
}
int main(){
  int x = 5;
  int y = 10;
  swap(x,y);
  return 0;
}
