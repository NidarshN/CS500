/*
 * File: ShapeClass.cpp
 * --------------------
 * This program tests the Shape classes by storing pointers to shapes
 * in a vector and then drawing them all at once. The picture is the
 * same as the GraphicsExample.cpp program from Chapter2.
 */

#include <iostream>
#include "vector.h"
#include "gwindow.h"
#include "shape.h"


int main(){
  GWindow gw;
  double width = gw.getWidth();
  double height = gw.getHeight();

  Rect *rp = new Rect(width / 4, height / 4, width / 2, height / 2);
  Oval *op = new Oval(width / 4, height / 4, width / 2, height / 2);
  Square *sq = new Square(width / 4, height / 4, width / 2);
  
  rp->setColor("BLUE");
  op->setColor("GRAY");
  sq->setColor("GREEN");

  Vector<Shape *> shapes;
  shapes.add(new Line(0, height / 2, width / 2, 0));
  shapes.add(new Line(width / 2, 0, width, height / 2));
  shapes.add(new Line(width, height / 2, width / 2, height));
  shapes.add(new Line(width / 2, height, 0, height / 2));
  shapes.add(rp);
  shapes.add(op);
  shapes.add(sq);

  for(Shape *sp: shapes){
    sp->draw(gw);
  }

  for(Shape *sp: shapes){
    delete sp;
  }

  shapes.clear();
  return 0;
}
