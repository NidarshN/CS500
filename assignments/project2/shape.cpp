/*
 * File: shape.cpp
 * ---------------
 * This file implements the shape.h interface.
 */

#include <string>
#include <iostream>
#include <cmath>
#include "gwindow.h"
#include "shape.h"


/*
 * Implementation notes: Shape class
 * ---------------------------------
 * The constructor for the superclass sets all shapes to BLACK, which is the default color.
 * The remaining methods simply set the instance variables.
 */


Shape::Shape(){
  setColor("BLACK");
}

void Shape::setLocation(double x, double y){
  this->x = x;
  this->y = y;
}

void Shape::move(double dx, double dy){
  x += dx;
  y += dy;
}

void Shape::setColor(std::string color){
  this->color = color; 
}

/*
 * Impelmentation notes: Line class
 * --------------------------------
 * The constructor for the Line class has to change the specification
 * of the line from the endpoints passed to the constructor to the
 * presentation that uses a starting point along with dx/dy values.
 */

Line::Line(double x1, double y1, double x2, double y2){
  this->x = x1;
  this->y = y1;
  this->dx = x2 - x1;
  this->dy = y2 - y1;
}

void Line::draw(GWindow & gw){
  gw.setColor(color);
  gw.drawLine(x, y, x + dx, y + dy);
}

bool Line::contains(double x, double y){
    double A = dy;
    double B = -dx;
    double C = dx * y - dy * x;
    double distance = fabs(A * x + B * y + C) / sqrt(A * A + B * B);

    return (distance <= 0.5);
}
/*
 * Implementation notes: Rect and Oval classes
 * -------------------------------------------
 * The constructors for these classes store their arguments in the
 * corresponding instance variables. The draw method for the shape
 * just forwards the request to the GWindow class.
 */

Rect::Rect(double x, double y, double width, double height){
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

void Rect::draw(GWindow & gw){
  gw.setColor(color);
  gw.fillRect(x, y, width, height);
}

bool Rect::contains(double x, double y){
  bool checkx = (x >= this->x && x <= (this->x + this->width));
  bool checky = (y >= this->y && y <= (this->y + this->height));

  return (checkx && checky);
   
}

Oval::Oval(double x, double y, double width, double height){
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

void Oval::draw(GWindow & gw){
  gw.setColor(color);
  gw.fillOval(x, y, width, height);
}

bool Oval::contains(double x, double y){
    double center_X = (this->x + this->width) / 2;
    double center_Y = (this->y + this->height) / 2;
    double a = (this->width) / 2;
    double b = (this->height) / 2;
    return ((( pow((x - center_X), 2) / pow(a, 2)) + (pow((y - center_Y), 2)/ pow(b,2))) <= 1);

}
/*
 * Implementation notes: Circle
 * ----------------------------
 * The Circle class is a subclass of Oval that interprets for which
 * the constructir interprets its arguments in a different way. This
 * constructor uses an initialization list to call the Oval constructor
 * with the correct arguments.
 */

Circle::Circle(double x, double y, double r)
  : Oval(x - y, y - r, 2 * r, 2 * r){
  /* Empty */
}



/*
 * Implementation notes: Square class
 * -------------------------------------------
 * The constructors for the square class store the arguments in the
 * corresponding instance variables. The draw method for the shape
 * just forwards the request to the GWindow class.
 */

Square::Square(double x, double y, double size){
  this->x = x;
  this->y = y;
  this->size = size;
}

void Square::draw(GWindow & gw){
  gw.setColor(color);
  gw.fillRect(x, y, size, size);
}

bool Square::contains(double x, double y){
  bool checkx = (x >= this->x && x <= (this->x + this->size));
  bool checky = (y >= this->y && y <= (this->y + this->size));

  return (checkx && checky);
}
