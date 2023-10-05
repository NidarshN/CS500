#include <iostream>

void hanoi1HardCoded(char start, char end);
void hanoi2HardCoded(char start, char spare, char end);
void hanoi3HardCoded(char start, char spare, char end);
void hanoi1CallingSimplerMethods(char start, char end);
void hanoi2CallingSimplerMethods(char start, char spare, char end);
void hanoi3CallingSimplerMethods(char start, char spare, char end);
void hanoi(char start, char spare, char end, int n);


int main(){
  int n;
  std::cout << "Enter the number of disks: " << std::endl;
  std::cin >> n;
  hanoi('A', 'B' , 'C', n);
  return 0;
}

void hanoi1HardCoded(char start, char end){
  std::cout << start << " -> " << end << std::endl;
}

void hanoi2HardCoded(char start, char spare, char end){
  std::cout << start << " -> " << spare << std::endl;
  std::cout << start << " -> " << end << std::endl;
  std::cout << spare << " -> " << end << std::endl;
}

void hanoi3HardCoded(char start, char spare, char end){
  std::cout << start << " -> " << end << std::endl;
  std::cout << start << " -> " << spare << std::endl;
  std::cout << end << " -> " << spare << std::endl;
  std::cout << start << " -> " << end << std::endl;
  std::cout << spare << " -> " << start << std::endl;
  std::cout << spare << " -> " << end << std::endl;
  std::cout << start << " -> " << end << std::endl;
}

void hanoi1CallingSimplerMethods(char start, char end){
  std::cout << start << " -> " << end << std::endl;
}

void hanoi2CallingSimplerMethods(char start, char spare, char end){
  hanoi1CallingSimplerMethods(start, spare);
  std::cout << start << " -> " << end << std::endl;
  hanoi1CallingSimplerMethods(spare, end);
}

void hanoi3CallingSimplerMethods(char start, char spare, char end){
  hanoi2CallingSimplerMethods(start, end, spare);
  std::cout << start << " -> " << end << std::endl;
  hanoi2CallingSimplerMethods(spare, start, end);
}

void hanoi(char start, char spare, char end, int n){
  //Implement this method
  if(n == 0){
    return;
  }else if(n == 1){
    return hanoi1CallingSimplerMethods(start, end);
  }else if(n == 2){
    return hanoi2CallingSimplerMethods(start, spare, end);
  }else if(n == 3){
    return hanoi3CallingSimplerMethods(start, spare, end);
  }else{
    hanoi(start, end, spare, n-1);
    std::cout << start << " -> " << end << std::endl;
    hanoi(spare, start, end, n-1);
  }
  
}
