/*
 * File: shape.h
 * -------------
 * This file defines a simple hierarchy of graphical shape classes.
 */

#ifndef _shape_h
#define _shape_h

#include <string>
#include "gwindow.h"

/*
 * Class: Shape
 * ------------
 * This class is the root of the hierarchy and encompasses all shapes.
 */

class Shape{
 public:

  /*
   * Method: setLocation
   * Usage: shape.setLocation(x, y);
   * -------------------------------
   * Sets the x and y coordinates of the shape to the specified values.
   */

      void setLocation(double x, double y);

   /*
    * Method: move
    * Usage: shape.mode(dx, dy);
    * --------------------------
    * Adds dx and dy to the coordinates of the shape.
    */

      void move(double x, double y);

   /*
    * Method: setColor
    * Usage: shape.setColor(color);
    * -----------------------------
    * Sets the color of the shape. The names of the available colors are
    * described in the gwindow.h interface.
    */
      void setColor(std::string color);

   /*
   * Abstract method: draw
   * Usage: shape.draw(gw);
   * ----------------------
   * Draws the shape on the GraphicsWindow specified by gw. This method
   * is implemented by the specific Shape subclasses.
   */
      virtual void draw(GWindow & gw) = 0;

  /*
   * Abstract method: contains
   * Usage: shape.contains(x, y);
   * ----------------------------
   * Checks whether the specified point is present inside the shape.
   */
      virtual bool contains(double x, double y) = 0;

 protected:

  /* The following methods and fields are available to the subclasses */
      Shape(); /* Superclass Constructor */
      std::string color; /* The color of the object */
      double x, y; /* The coordinates of the object */
};

/*
 * Subclass: Line
 * --------------
 * The Line subclass represents a line segment on the window.
 */

class Line : public Shape {
 public:

  /*
   * Constructor: Line
   * Usage: Line line(x1, y1, x2, y2);
   * ---------------------------------
   * Creates a line segment that extends from (x1, y1) to (x2, y2).
   */

      Line(double x1, double y1, double x2, double y2);

  /* Prototypes for the overridden virtual methods */

      virtual void draw(GWindow & gw);

  /* Prototypes for the overridden virtual methods */

      virtual bool contains(double x, double y);

 private:
      double dx; /* Horizontal distance from x1 to x2 */
      double dy; /* Vertical distance from y1 to y2 */

};


/*
 * Subclass: Rect
 * --------------
 * The Rect sublcass represents a solid rectangle.
 */

class Rect : public Shape {
 public:

  /*
   * Constructor: React
   * Usage: Rect rect(x, y, width, height);
   * --------------------------------------
   * Creates a rectangle of the specified size and upper left corner at (x, y).
   */

      Rect(double x, double y, double width, double height);

  /* Prototypes for the overridden virtual methods */

      virtual void draw(GWindow & gw);

  /* Prototypes for the overridden virtual methods */

      virtual bool contains(double x, double y);

 private:

      double width, height; /* Dimensions of the rectangle */
      
};

/*
 * Subclass: Oval
 * --------------
 * The Oval subclass represents a solid oval defined by a bounding rectangle.
 */

class Oval : public Shape {
 public:

  /*
   * Constructor: Oval
   * Usage: Oval oval(x, y, width, height);
   * -------------------------------------
   * Creates an oval that fits inside the rectangle indicated by the arguments.
   */

      Oval(double x, double y, double width, double height);

  /* Prototypes for the overridden virtual methods */

      virtual void draw(GWindow & gw);
  
  /* Prototypes for the overridden virtual methods */

      virtual bool contains(double x, double y);

 private:

  double width, height; /* Dimensions of the bounding rectangle */
};

/*
 * Subclass: Circle
 * ----------------
 * The Circle subclass represents a solid circle.
 */

class Circle : public Oval {

public:

  /*
   * Constructor: Circle
   * Usage: Circle circle(x, y ,r);
   *        Circle *cp = new Circle(x, y, r);
   * ----------------------------------------
   * Creates a circle of radius r centered at the point (x, y);
   */

      Circle(double x, double y, double r);
  
};


/*
 * Subclass: Square
 * ----------------
 * The Square subclass represents a solid square
 */

class Square : public Shape {
public:
  /*
   * Constructor: Square
   * Usage: Square square(x, y, size);
   * ---------------------------------
   * Creates a square of the specified size and upper left corner at (x, y)
   */

      Square(double x, double y, double size);
  
  /* Prototypes for the overridden virtual methods */
      virtual void draw(GWindow & gw);

  /* Prototypes for the overridden virtual methods */

      virtual bool contains(double x, double y);
  
private:

      double size; /* Dimension of the square */
};

#endif
