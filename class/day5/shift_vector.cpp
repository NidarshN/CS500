#include <iostream>
#include <vector>

void shift(std::vector<std::pair<int, int> > & nums){
  for(size_t i = 0; i < nums.size(); ++i){
    auto [num1, num2] = nums[i];
    num1++;
    num2++;
  }
}

void shiftByRef(std::vector<std::pair<int, int> > & nums){
  for(size_t i = 0; i < nums.size(); ++i){
    auto &[num1, num2] = nums[i];
    num1++;
    num2++;
  }
}

void printVec(std::vector<std::pair<int, int> > vec_pair){
  for(size_t i = 0; i < vec_pair.size(); ++i){
    std::cout << "Pair " << i+1 <<" : " << std::endl;
    auto [num1, num2] = vec_pair[i];
    std::cout << std::endl<< "Num1 : " << num1
	      << std::endl << "Num2: " << num2 << std::endl << std::endl;
  }
  std::cout << std::endl;
}

int main(){
  std::vector<std::pair<int, int> > vec_pair = {{1,3}, {2,4}, {3,5}};

  std::cout << "Shift Vector by Value: " << std::endl;
  shift(vec_pair);
  printVec(vec_pair);

  std::cout << "Shift Vector by Reference: " << std::endl;
  shiftByRef(vec_pair);
  printVec(vec_pair);
  
  return 0;
}
