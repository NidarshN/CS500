#include <iostream>
#include <math.h>

void primefactor(int n){
  int i = 0;
  while(n % 2 == 0){
    std::cout << "2 " << "\t";
    n /= 2;
  }

  for(i=3; i <= sqrt(n); i += 2){
    while(n % i == 0){
      std:: cout << i << " \t";
      n = n / i;
    }
  }

  if(n > 2){
    std::cout<<n<<"\t";
  }
}

int main(){
  int num = 0;

  std::cout<< "Enter the number: ";
  std::cin >> num;
  std::cout<<"The prime factors are ";
  primefactor(num);
  return 0;
}
