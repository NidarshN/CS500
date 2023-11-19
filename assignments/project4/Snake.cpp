#include <NonBlockingGame.h>
#include <iostream>
#include <time.h>
#include <vector>


//
//  The purpose of this assignment is to learn to 1. The classic game of Snake.
//  Move a "snake" (line of sprites) along a 2D grid attempting to run over a
//  randomly placed object to help it grow. 2. If it runs into itself the game is over
//  and the player has lost. 3. The object of the game is to make the snake as big as possible.
//
using namespace bridges::game;
using namespace std;

// this keeps a list of elements (squares) that represents the snake object
// linked list since it can grow as the game progresses
class Block {
  public:
    Block *next = nullptr;
    int x;
    int y;
    Block() {
      x = 0;
      y = 0;
    }
    Block(int x, int y) {
      this->x = x;
      this->y = y;
    }
};

struct my_game : public NonBlockingGame {
  long frameTime;
  long nextFrameTime;

    //TODO: create a variable to represent an apple, what type should it be?
  Block apple;
    //TODO: create a variable to represent the head, what type should it be?
  Block head;

  enum Direction {East, West, South, North};
    
    //TODO: create a variable to store the last direction and initialize it to east
  Direction lastDir = East;
    //TODO: create a variable to store the current direction and initialize it to east
  Direction currentDir = East;

  int frame = 0;
  NamedColor headColor = NamedColor::blueviolet;
  NamedColor bodyColor = NamedColor::cyan;
  NamedColor appleColor = NamedColor::red;

  my_game(int assID, std::string username, std::string apikey)
    : NonBlockingGame (0, username, apikey, 30, 30) {
  }

  virtual void initialize() override {
    srand(time(NULL));

      //TODO: initialize the head to a new block starting at the point 15, 15
    head = Block(15, 15);
      //TODO: create a pointer to head
    Block* current = &head;
      //This code draws the rest of the snake
      //TODO: what color would you like your snake? The default is silver as you can see
    for (int i = 0; i < 3; i++) {
      setBGColor(15 - i, 15, bodyColor);

      if (i > 0) {
        current->next = new Block(15 - i, 15);
        current = current->next;
      }
    }

      //TODO: set the current direction to east
      currentDir = East;
      //TODO: set the last direction equal to the current direction
      lastDir = currentDir;
      //TODO: initialize an apple to a block at 0,0
      apple = Block(0, 0);
      //TODO: plant the apple
      plantApple();
      //TODO: paint the screen
      paint();
  }

  void handleInput() {
      //TODO: test which key was pressed (ex: keyLeftJustPressed())
      //if the user pressed left, change the current direction to west as long as the
      //the last direction does not equal east...the snake can't just flip
      //Do for up, down, left, right

    // Change the direction of the head to West if left key is pressed and if last direction is not East
    if (keyLeftJustPressed() && lastDir != Direction::East) {
        currentDir = Direction::West;
    // Change the direction of the head to East if right key is pressed and if last direction is not West
    }else if (keyRightJustPressed() && lastDir != Direction::West) {
        currentDir = Direction::East;
    // Change the direction of the head to North if up key is pressed and if last direction is not South
    }else if (keyUpJustPressed() && lastDir != Direction::South) {
        currentDir = Direction::North;
    // Change the direction of the head to South if down key is pressed and if last direction is not North
    }else if (keyDownJustPressed() && lastDir != Direction::North) {
        currentDir = Direction::South;
    }
  }

  // update snake position
  void updatePosition() {
    Block * current = head.next;
    int nextX = head.x;
    int nextY = head.y;
    Block nextPos = head;

      //TODO: loop through the snake's body setting each node's (x,y) to the next node's (x,y)
    while (current != nullptr) {
        int tempX = current->x;
        int tempY = current->y;
        current->x = nextX;
        current->y = nextY;
        nextX = tempX;
        nextY = tempY;
        current = current->next;
    }

      // TODO: handle edge cases
      //hint: a switch statement on the current direction would be really helpful

    /**
    *  Update the position of the snake's head based on the current direction.
    *  The switch statement handles different directions:
    *  - If moving East, increment the y-coordinate of the head, and wrap around if it goes beyond the board width.
    *  - If moving West, decrement the y-coordinate of the head, and wrap around if it goes below zero.
    *  - If moving North, decrement the x-coordinate of the head, and wrap around if it goes below zero.
    *  - If moving South, increment the x-coordinate of the head, and wrap around if it goes beyond the board height.
    */
    switch (currentDir) {
        case Direction::East:
            head.y = (head.y + 1 + getBoardWidth()) % getBoardWidth();
            break;
        case Direction::West:
            head.y = (head.y - 1 + getBoardWidth()) % getBoardWidth();
            break;
        case Direction::North:
            head.x = (head.x - 1 + getBoardHeight()) % getBoardHeight();
            break;
        case Direction::South:
            head.x = (head.x + 1) % getBoardHeight();
            break;
    }
  }

  // locate apple at new position
  void plantApple() {
    int x;
    int y;

      //TODO: get a new random x and a random y for the apple
      //loop through the snake to ensure that the apple's (x,y) does not
      //intersect with any part of the snake, if it does, get new random values to test
      //if it doesn't collide with the snake, set the apple's x and apple's y to the random
      //values that were identified
    bool doesCollide = false;
    
    do {
        doesCollide = false;
        x = rand() % getBoardWidth();
        y = rand() % getBoardHeight();

        Block* current = &head;

        while (current != nullptr) {
            if (current->x == x && current->y == y) {
                doesCollide = true;
                break;
            }
            current = current->next;
        }

    } while (doesCollide);

    // Set the apple's x and y to the random values that were identified
    apple.x = x;
    apple.y = y;
  }

  // check if snake has found the apple
  void detectApple() {
      //Tests to see if the snake has hit the apple
      //Erases the apple
    if (head.x == apple.x && head.y == apple.y) {
      drawSymbol(apple.x, apple.y, NamedSymbol::none, appleColor);

        //TODO: Make the snake longer by adding a new block to the end of the snake
      Block* current = &head;
      while (current->next != nullptr) {
        current = current->next;
      }
      current->next = new Block(apple.x, apple.y);

        //Plant a new apple
      plantApple();
    }
  }

  // check if snake ate itself! Yuk!
  /**
   * Check if the snake has collided with itself, leading to the end of the game.
   * If a collision is detected, deallocates the memory occupied by the snake's body.
   * Exits the program after deallocating memory to terminate the game.
 */
  void detectDeath() {
    Block * current = head.next;
    while (current != nullptr) {
      if (head.x == current->x && head.y == current->y) {
        // TODO: need to deallocate storage!
        while (head.next != nullptr) {
          Block* temp = head.next;
          head.next = temp->next;
          delete temp;
        }
        exit(0);
      }
      current = current->next;
    }
  }


  // redraw
  void paint() {
      //Paints the board by looping through the rows and columns
      //Optional TODO: change the color of the board
    for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 30; j++) {
        if (i % 2 == j % 2) {
          setBGColor(i, j, NamedColor::green);
        }
        else {
          setBGColor(i, j, NamedColor::forestgreen);
        }
      }
    }

      //Optional TODO: change the color of the head of the snake
    setBGColor(head.x, head.y, headColor);

      //Optional TODO: use a different symbol or color
    drawSymbol(apple.x, apple.y, NamedSymbol::apple, appleColor);

      //Paints the snake
      //Optional TODO: change the color of the snake
    Block * current = head.next;
    while (current != nullptr) {
      setBGColor(current->x, current->y, bodyColor);
      current = current->next;
    }
  }

  // handle input, check if apple was detected, update position, redraw,
  // detect if snake ate itself
  /**
   * Implementation of the game loop, which manages the game's main logic and updates.
   * It increments the frame count, handles user input, and performs game actions every frame.
   * Actions include updating the snake's position, detecting if it ate an apple,
   * redrawing the game board, checking for snake collisions, and resetting the frame count.
 */
  virtual void gameLoop() override {
    frame += 1;
    handleInput();
    if (frame >= 5) {
      lastDir = currentDir;
      detectApple();
      updatePosition();
      paint();
      detectDeath();
      frame = 0;
    }
  }
};

// Initialize your game
// Call your game class with your assignment id, username, and api key
int main (int argc, char** argv) {
  my_game g(1, "nidarsh", "542201624984");

  g.start();
}
