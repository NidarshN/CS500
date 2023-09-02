#include <iostream>
#include <vector>

void printVector(std::vector<int> &vec);
void mergeSorted(std::vector<int> &vec, int low, int high);
void merge(std::vector<int> &vec, int low, int mid, int high);

int main(){
  int vec1_size, vec2_size, temp;

  std::cout << "Enter the size of vector 1: " << std::endl;
  std::cin >> vec1_size;

  std::vector<int> vector1(vec1_size);
  
  for(int i=0; i < vec1_size; ++i){
    std::cout << "Enter the " << i+1 << "th element for vector1: "
              << std::endl;
    std::cin >> temp;
    vector1[i] = temp;
  }

  std::cout << "Vector 1: " << std::endl;
  printVector(vector1);

  mergeSorted(vector1, 0, vec1_size - 1);

  std::cout << "After merge sort, " << "Vector 1: " << std::endl;
  printVector(vector1);

  std::cout << "Enter the size of vector 2: " << std::endl;
  std::cin >> vec2_size;

  std::vector<int> vector2(vec2_size);

  for(int i=0; i < vec2_size; ++i){
    std::cout << "Enter the  " << i+1 << "th element for vector2: "
	      << std::endl;
    std::cin >> temp;
    vector2[i] = temp;
  }

  mergeSorted(vector2, 0, vec2_size - 1);

  std::cout << "After merge sort, " << "Vector 2: " << std::endl;
  
  printVector(vector2);

  vector1.insert(vector1.end(), vector2.begin(), vector2.end());

  std::cout << "Concatenated Vectors - Vector 1 and Vector 2: " << std::endl;

  printVector(vector1);

  int concat_vec_size = vector1.size();

  mergeSorted(vector1, 0, concat_vec_size - 1);

  std::cout << "After merge sort, " << "Concatenated Vector: " << std::endl;
  
  printVector(vector1);
  
  
  return 0;
}

void merge(std::vector<int> &vec, int low, int mid, int high){
  int leftInd = (mid - low) + 1;
  int rightInd = (high - mid);
 
 
  std::vector<int> leftVec(leftInd), rightVec(rightInd);

  
  for(int i = 0; i < leftInd; ++i){
    int temp = vec[low+i];
    leftVec[i] = temp;
  }

  for(int i=0; i < rightInd; ++i){
    int temp = vec[mid + 1 + i];
    rightVec[i] = temp;

  }

  int i = 0, j = 0, k = low;

  while(i < leftInd && j < rightInd){
    if(leftVec[i] <= rightVec[j]){
      int temp = leftVec[i];
      vec[k] = temp;
      ++i;
    }else{
      int temp = rightVec[j];
      vec[k] = temp;
      ++j;
    }
    ++k;
  }

  while(i < leftInd){
    int temp = leftVec[i];
    vec[k] = temp;
    ++i;
    ++k;
  }

  while(j < rightInd){
    int temp = rightVec[j];
    vec[k] = temp;
    ++j;
    ++k;
  }

 

}
void mergeSorted(std::vector<int> &vec, int low, int high){
  if(low < high){
    int mid = low + (high - low) / 2;
    mergeSorted(vec, low, mid);
    mergeSorted(vec, mid + 1, high);
    merge(vec, low, mid, high);
  }
}

void printVector(std::vector<int> &vec){
  for(int i=0; i < vec.size(); ++i){
    std::cout << vec[i] << "\t";
  }
  std::cout << std::endl;
}
