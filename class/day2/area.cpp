#include <iostream>
#include <string>

double area(double length);
double area(double length, double breadth);

int main(){

  double length, breadth;
  std::string shape;
  
  std::cout << "Enter the shape whose area you want to calculate: (rectangle, square) ";
  
  std::cin >> shape;

  if(shape.compare("rectangle") == 0){
      std::cout << "Enter the length: " << std::endl;
      std::cin >> length;
      std:: cout << "Enter the breadth: " << std::endl;
      std::cin >> breadth;
      std::cout << "Area of the rectangle("
	      << length << "x" << breadth << "): "
              << area(length, breadth) << std::endl;
  }else if(shape.compare("square") == 0){
      std::cout << "Enter the length: " << std::endl;
      std::cin >> length;
      std::cout << "Area of the square("
	      << length << "x" << length << "): "
              << area(length) << std::endl;
  }
 
  return 0;
}


double area(double length){
  return length * length;
}

double area(double length, double breadth){
  return length * breadth;
}
