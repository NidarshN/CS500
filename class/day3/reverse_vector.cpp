#include <iostream>
#include <vector>

std::vector<int> reverse(std::vector<int> intVector);

int main(){

  std::vector<int> intVector;
  int n;
  int element;
  
  std::cout << "Enter the number of elements needed for the vector" <<std::endl;
  std::cin >> n;

  for(int i = 0; i < n; i++){
    std::cout<< "Enter the element to be inserted: " << std::endl;
    std::cin >> element;
    intVector.push_back(element);
  }

  intVector = reverse(intVector);

  std::cout << "The Reverse Vector Sequence: " << std::endl;
  
  for(int i = 0; i < n; i++){
    std::cout << intVector[i] << "\t";
  }
  std::cout << std::endl;
  
  return 0;
}

std::vector<int> reverse(std::vector<int> intVector){
  int vec_size = intVector.size();
  std::vector<int> copyVector(vec_size);
  
  for(int i = 0; i < vec_size; ++i){

    int temp = intVector[i];

    copyVector.at(vec_size - i - 1) = temp;
  }
  return copyVector;
}
