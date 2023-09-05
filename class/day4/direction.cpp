#include <iostream>
#include <string>
#include "direction.h"

Direction leftFrom(Direction dir_from){
  return Direction((dir_from + 3) % 4);
}

Direction rightFrom(Direction dir_from){
  return Direction((dir_from + 1) % 4);
}

std::string directionToString(Direction dir){
  switch(dir){
      case NORTH: return "North";
	break;
      case EAST: return "East";
        break;
      case SOUTH: return "South";
        break;
      case WEST: return "West";
        break;
      default: return "Invalid";
        break;
  }
}

Direction stringToDirection(std::string dir){
  if(dir.compare("North") == 0)
    return NORTH;
     else if(dir.compare("East") == 0)
    return EAST;
     else if(dir.compare("South") == 0)
    return SOUTH;
     else if(dir.compare("West") == 0)
    return WEST;
  else
    return NORTH;
}

int main(){
  Direction dir = NORTH;
  std::string str_dir = "";
  std::cout << "Enter the direction(North, East, South, West): " << std::endl;
  std::cin >> str_dir;

  dir = stringToDirection(str_dir);

  
  
  std::cout << "Left From: " << directionToString(leftFrom(dir)) << std::endl;
  std::cout << "Right From: " << directionToString(rightFrom(dir)) << std::endl;
  std::cout << "To String: " << directionToString(dir) << std::endl;
  return 0;
}
