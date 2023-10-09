#include <iostream>
#include <climits>
#include <string>

class TicTacToe {
public:
    TicTacToe(char playerPiece) {
        for (int i = 0; i < 9; ++i) {
            board[i] = char(i + 49);
        }
        player = (playerPiece == 'O')? 'O': 'X';
        computer = (player == 'X') ? 'O' : 'X';
    }

    void play() {
        while (determineWinner() == '?' && !isFull()) {
            drawboard();
            playerMove(getPlayerPosition());
            if (determineWinner() == '?' && !isFull()) {
                computerMove();
            }
        }
        char winner = determineWinner();
        drawboard();
        if (winner == player)
            std::cout << "You won! Congratulations!";
        else if (winner == computer)
            std::cout << "You lost...sorry! Try again!";
        else
            std::cout << "Tie! Great playing!";
    }

private:
    void drawboard() {
        std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
        std::cout << " " << "-" << " | " << "-" << " | " << "-" << std::endl;
        std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
	std::cout << " " << "-" << " | " << "-" << " | " << "-" << std::endl;
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
        int currentBestScore = INT_MIN;
        int bestMove = -1;

        for (int i = 0; i < sizeof(board); i++) {
            if (isAvailable(char(i + 49))) {
                board[i] = computer;
                int score = miniMax(board, 0, true);
                board[i] = char(i + 49); 

                if (score > currentBestScore) {
                    currentBestScore = score;
                    bestMove = i;
                }
            }
        }

        if (bestMove != -1) {
            board[bestMove] = computer;
        }
    }

    int miniMax(char fboard[], int depth, bool isMinimizing) {
	char winner = determineWinner();
        if (winner == computer) {
            return 1 * depth;
        } else if (winner == player) {
            return -1 * depth;
        }
        
        if (isFull()) {
            return 0;
        }

        if (isMinimizing) {
	   int bestScore = INT_MAX;
            for (int i = 0; i < std::strlen(fboard); i++) {
                if (isAvailable(char(i + 49))) {
                    fboard[i] = player;
		    int moveScore = miniMax(fboard, depth + 1,  !isMinimizing);
                    bestScore = std::min(bestScore, moveScore);
                    fboard[i] = char(i + 49);
                }
            }
            return bestScore;
        } else {
           int bestScore = INT_MIN;
            for (int i = 0; i < std::strlen(fboard); i++) {
                if (isAvailable(char(i + 49))) {
                    fboard[i] = computer;
		    int moveScore = miniMax(fboard, depth + 1, !isMinimizing);
                    bestScore = std::max(bestScore,moveScore);
                    fboard[i] = char(i + 49);
                }
            }
            return bestScore;
        }
	return 0;
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
        } while (!isAvailable(move));
        return move;
    }

    bool isAvailable(char pos) {
        int position = int(pos) - 48;
        if (board[position - 1] == pos)
            return true;
        return false;
    }

    bool isFull() {
        for (int i = 0; i < 9; i++) {
            if (board[i] == char(i + 49))
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
    std::cout << "Do you want to be X or O (Default: X)?";
    std::cin >> piece;
    
    TicTacToe gameOn(piece);
    gameOn.play();
    
    return 0;
}
