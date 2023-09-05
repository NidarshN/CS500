#ifndef _direction_h
#define _direction_h
#include <string>

enum Direction {NORTH, EAST, SOUTH, WEST};

Direction leftFrom(Direction dir_from);
Direction rightFrom(Direction dir_from);
std::string directionToString(Direction dir);

#endif
