#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>



void printZero(long size);
void printOne(long size);
void printTwo(long size);
void printThree(long size);
void printFour(long size);
void printFive(long size);
void printSix(long size);
void printSeven(long size);
void printEight(long size);
void printNine(long size);

void printDigit(long size, int dig);

void getDigit(long size, long num);

void readData();


int main(){

  readData();
  
  return 0;
}

void readData(){

  std::ifstream inputFile("display_lcd.txt");
  
    if (!inputFile) {
      std::cout << "Error opening the file." << std::endl;
        return ;
    }
    
    unsigned long size, num;
    
    while (inputFile >> size >> num) {
      std::cout << "Size: " << size << " Num: " << num << std::endl;
      
      getDigit(size, num);
      
    }
    
    inputFile.close();
    

}


void getDigit(long size, long num){
  unsigned long temp_n = num, rev;
  int dig;
  while(temp_n > 0){
    dig = (int) temp_n % 10;
    printDigit(size, dig);
    temp_n /= 10;
  }
}

void printDigit(long size, int dig){
  switch(dig){
  case 0: printZero(size);
    break;
  case 1: printOne(size);
    break;
  case 2: printTwo(size);
    break;
  case 3: printThree(size);
    break;
  case 4: printFour(size);
    break;
  case 5: printFive(size);
    break;
  case 6: printSix(size);
    break;
  case 7: printSeven(size);
    break;
  case 8: printEight(size);
    break;
  case 9: printNine(size);
    break;

  }
}


void printZero(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows - 1; ++i){
    if(i == (rows / 2))
      continue;
    digit[i][0] = '|';
    digit[i][cols-1] = '|';
  }

  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}

void printOne(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];
  
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  for(int i=1; i < rows - 1; ++i){
    if(i == (rows / 2))
      continue;
    digit[i][cols-1] = '|';
    
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }
}

void printTwo(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows / 2; ++i){
    digit[i][cols-1] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }

  for(int i= rows/2 + 1; i < rows -1 ; ++i){
    digit[i][0] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}



void printThree(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows - 1; ++i){
    if(i == (rows / 2))
      continue;
    digit[i][cols-1] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}


void printFour(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];
  
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  for(int i=1; i < rows / 2; ++i){
    digit[i][0] = '|';
    
  }
  
  for(int i=1; i < rows - 1; ++i){
    if(i == (rows / 2))
      continue;
    digit[i][cols-1] = '|';
    
  }

  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }
}


void printFive(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows / 2; ++i){
    digit[i][0] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }

  for(int i= rows/2 + 1; i < rows -1 ; ++i){
    digit[i][cols - 1] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}

void printSix(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows / 2; ++i){
    digit[i][0] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }

  for(int i= rows/2 + 1; i < rows -1 ; ++i){
    digit[i][0] = '|';
    digit[i][cols - 1] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}


void printSeven(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];
  
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }


  for(int i=1; i < rows - 1; ++i){
    if(i == (rows / 2))
      continue;
    digit[i][cols-1] = '|';
    
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }
}


void printEight(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows / 2; ++i){
    digit[i][0] = '|';
    digit[i][cols - 1] ='|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }

  for(int i= rows/2 + 1; i < rows -1 ; ++i){
    digit[i][0] = '|';
    digit[i][cols - 1] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}

void printNine(long size){
  int rows = (2 * size) + 3;
  int cols = (size + 2);

  char digit[rows][cols];

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      digit[i][j] = ' ';
    }
  }

  
  for(int i=1; i < cols -1; ++i){
    digit[0][i] = '-';
  }

  for(int i=1; i < rows / 2; ++i){
    digit[i][0] = '|';
    digit[i][cols - 1] ='|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows / 2][i] = '-';
  }

  for(int i= rows/2 + 1; i < rows -1 ; ++i){
    //digit[i][0] = '|';
    digit[i][cols - 1] = '|';
  }
  
  for(int i=1; i < cols -1; ++i){
    digit[rows - 1][i] = '-';
  }

  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      std::cout << digit[i][j];
    }
    std::cout << std::endl;
  }

}
