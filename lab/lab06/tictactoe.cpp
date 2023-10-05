#include <iostream>

class TicTacToe {

public: 

  TicTacToe(char playerPiece){
    //Build the board
    for(int i = 0; i < sizeof(board); i++)
      board[i] = char(i+49);
    player = playerPiece;
    computer = (player == 'X') ? 'O' : 'X';
  }

  void play() {
    while(determineWinner() == '?' && !isFull()) {
      drawboard();
      playerMove(getPlayerPosition());
      if(determineWinner() == '?' && !isFull()) {
	computerMove();
      }
    } 
    char winner = determineWinner();
    drawboard();
    if(winner == player)
      std::cout << "You won! Congratulations!";
    else if(winner == computer)
      std::cout << "You lost...sorry! Try again!";
    else
      std::cout << "Tie! Great playing!";
  }

private:
  void drawboard(){
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
  }

  char determineWinner() {
    if(board[0] == board[1] && board[1] == board[2])
      return board[0];
    if(board[3] == board[4] && board[4] == board[5])
      return board[3];
    if(board[6] == board[7] && board[7] == board[8])
      return board[6];
    if(board[0] == board[3] && board[3] == board[6])
      return board[0];
    if(board[1] == board[4] && board[4] == board[7])
      return board[1];
    if(board[2] == board[5] && board[5] == board[8])
      return board[2];
    if(board[0] == board[4] && board[4] == board[8])
      return board[0];
    if(board[2] == board[4] && board[4] == board[6])
      return board[2];
    return '?';
  }

  void computerMove() {
    char fboard = board;
    int depth = 0;
    int result = 0;
    bool minState = true;
    
    for(int i=0; i < sizeof(board); i++){
      if(isAvailable(char(i+49)){
	  ++depth;
      }
    }

    result = minMax(fboard, depth, minState);
      
    for(int i = 0; i < sizeof(board); i++) {
      if(isAvailable(char(i+49))){
	  board[i] = computer;
	  return;
      }
    }
    return;
  }
  
  int minMax(char board[], int depth, bool min){
    char winner = determineWinner();
    
    if(winner == player){
      return 1 * depth;
    }else if(winner == computer){
      return -1 * depth;
    }else if{isFull()}{
      return 0;
    }
    

    for(int i = 0; i < sizeof(board); i++){
      if(isAvailable(char(i+49)){
	  
      }
    }
  }
  
  void playerMove(char move) {
    int pos = int(move) - 49;
    board[pos] = player;
  }

  char getPlayerPosition() {
    char move;
    do {
      std::cout << "Enter a move (1-9): ";
      std::cin >> move;
    } while(!isAvailable(move));
    return move;
  }

  bool isAvailable(char pos) {
    int position = int(pos) - 48;
    if(board[position - 1] == pos)
      return true;
    return false;
  }

  bool isFull() {
    for(int i = 0; i < sizeof(board); i++) {
      if(board[i] == char(i+49))
	return false;
    }
    return true;
  }

    char board[9];
    char player;
    char computer;
  };
    
  int main() {
    char piece;   
    std::cout << "Do you want to be X or O? ";
    std::cin >> piece;

    TicTacToe gameOn(piece);
    gameOn.play();

    return 0;
  }
