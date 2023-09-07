#include <iostream>
#include <fstream>
#include <string>
#include <vector>


std::vector<unsigned long> readData(std::string filename);
void printVec(std::vector<unsigned long> vec_data);
bool checkPalindrome(unsigned long num);
unsigned long reverseNum(unsigned long num);
void revAdd(unsigned long num);
void getPalindrome(std::vector<unsigned long> vec_data);

const unsigned long UPPER_LIMIT = 4294967295;

int main(){

  const std::string filename = "reverse_add_palindrome.txt";
 
  std::vector<unsigned long>  vec_data = readData(filename);

  printVec(vec_data);

  std::cout << std::endl << "Output: " << std::endl << std::endl;
  
  getPalindrome(vec_data);


  return 0;
}

void getPalindrome(std::vector<unsigned long> vec_data){
  for(int i=1; i < vec_data.size(); i++){
    revAdd(vec_data[i]);
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
    std::cout << "For " << temp_num
	      << ", Palindrome does not exist!" << std::endl;
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


void printVec(std::vector<unsigned long> vec_data){
  std::cout << std::endl << "Vector Data: " << std::endl;
  for(int i = 0; i < vec_data.size(); ++i){
    std::cout << vec_data[i] << std::endl;
  }

  std::cout << std::endl;
}


std::vector<unsigned long> readData(std::string filename){
  std::ifstream dataFile (filename);
  std::string dataLine;
  unsigned long temp;
  std::vector<unsigned long> vec_data;
  
  if(dataFile.is_open()){
    while(dataFile){
      std::getline(dataFile, dataLine);
      if(!dataLine.empty()){
	 temp = std::strtoull(dataLine.c_str(), NULL, 10);
	 vec_data.push_back(temp);
      }
     
    }
  }
  return vec_data;
}
