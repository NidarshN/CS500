#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>



void printOne(int size);
std::vector<map<int, int> > readData(std::string file_name);

int main(){
  
  
  return 0;
}

void printOne(int size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  

}
std::vector<map<int, int> > readData(std::string file_name){

  
  std::vector<map<int, int> > vec_data;

  stf::ifstream dataFile (file_name);
  std::string dataLine;
  unsigned long temp;

  if(dataFile.is_open()){
    while(dataFile){
      std::getline(dataFile, dataLine);
      if(!dataLine.empty){
	

      }
    }
  }
  

}
