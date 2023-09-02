#include <iostream>
#include <vector>


void printVector(std::vector<int> &vec);
void mergeSort(std::vector<int> &vec, int low, int high);
void merge(std::vector<int> &vec, int low, int mid, int high);

int main(){

  int vec_size = 0, temp = 0;

  std::cout << "Enter the size of the vector: " << std::endl;
  std::cin >> vec_size;

  std::vector<int> vector1(vec_size);

  std::cout << "Enter the elements for vector: " << std::endl;
  for(int i = 0; i < vec_size; ++i){
    std::cout << "Enter the " << i+1 <<"th element for vector: " << std::endl;
    std::cin >> temp;

    vector1[i] = temp;
  }

  std::cout << "Vector 1 Elements are: " << std::endl;

  printVector(vector1);

  mergeSort(vector1, 0, vec_size - 1);

  std::cout << "After Merge Sort, Vector Elements are: " << std::endl;

  printVector(vector1);
  
  return 0;
}

void mergeSort(std::vector<int> &vec, int low, int high){
  if(low < high){
    
    int mid = low + (high - low) / 2;

    mergeSort(vec, low, mid);
    mergeSort(vec, mid + 1, high);
    merge(vec, low, mid, high);
  }
}

void merge(std::vector<int> &vec, int low, int mid, int high){

  int leftInd = mid - low + 1;
  int rightInd = high - mid;

  std::vector<int> leftVec(leftInd), rightVec(rightInd);

  for(int i = 0; i < leftInd; ++i){
    int temp = vec[low + i];
    leftVec[i] = temp;
  }

  for(int i = 0; i < rightInd; ++i){
    int temp = vec[mid + 1 + i];
    rightVec[i] = temp;
  }


  int i = 0, j = 0, k = low;

  while(i < leftInd && j < rightInd){
    if(leftVec[i] <= rightVec[j]){
      int temp = leftVec[i];
      vec[k] = temp;
      ++i;
    }else {
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

void printVector(std::vector<int> &vec){

  for(int i = 0; i < vec.size(); ++i){
    std::cout << vec[i] << "\t";
  }

  std::cout << std::endl;
}
