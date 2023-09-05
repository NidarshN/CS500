#include <iostream>

bool checkPalindrome(unsigned long num);
unsigned long reverseNum(unsigned long num);
void printArr(unsigned long arr[], int arr_size);
void revAdd(unsigned long num);
void getPalindrome(unsigned long num_arr[], int num_cases);

const unsigned long UPPER_LIMIT = 4294967295;

int main(){

  int num_cases = 0;
 

  std::cout << "Enter the number of test cases: " << std::endl;
  std::cin >> num_cases;

  unsigned long res_arr[num_cases], num_arr[num_cases];
  int min_iter_arr[num_cases];

  std::cout << "Enter the " << num_cases << " test cases: " << std::endl;
  for(int i=0; i < num_cases; ++i){
    std::cin >> num_arr[i];
  }

  std::cout << std::endl << "Output: " << std::endl;
  
  getPalindrome(num_arr, num_cases);


  return 0;
}

void getPalindrome(unsigned long num_arr[], int num_cases){
  for(int i=0; i < num_cases; i++){
    revAdd(num_arr[i]);
  }
}

void revAdd(unsigned long num){
  unsigned long res_num = 0, count = 1, temp_num = num;
  while(num < UPPER_LIMIT){
    res_num = reverseNum(num);
    num += res_num;

    if(checkPalindrome(num)){
      std::cout << count << " " << num << std::endl;
      break;
    }
    ++count;
  }

  if(num > UPPER_LIMIT){
    std::cout << "For " << temp_num << ", Palindrome does not exist!" << std::endl;
  }
  return;
}

unsigned long reverseNum(unsigned long num){
  unsigned long rem_num = 0, temp_n = num;
  int digit;
  
  while(temp_n > 0){
    digit = temp_n % 10;
    rem_num = (rem_num * 10) + digit;
    temp_n /= 10; 
  }

  return rem_num;
}

bool checkPalindrome(unsigned long num){
  unsigned long rev_num = 0;
  rev_num = reverseNum(num);

  return rev_num == num;

}


void printArr(unsigned long arr[], int arr_size){
  for(int i = 0; i < arr_size; ++i){
    std::cout << arr[i] << std::endl;
  }

  std::cout << std::endl;
}
