#include <iostream>
#include <map>
#include <string>
#include <iomanip>

int main(){

  double menu_total = 0.0;
  std::string item1, item2;

  std::map<std::string, double> menu_map;

  menu_map["Burger"] = 20.0;
  menu_map["Pancake"] = 12.50;
  menu_map["Chocolate Shake"] = 9.99;
  menu_map["Vanilla Shake"] = 8.99;
  menu_map["Cheese Bread"] = 6.76;

  std::map<std::string, double>::iterator iter =  menu_map.begin();

  std::cout << "***** MENU *****" << std::endl;
  std::cout << "Item (" << "Price)" << std::endl;

  while(iter !=  menu_map.end()){
    std::cout << iter->first << " (" << iter->second << ")" << std::endl;
    ++iter;
  }

  std::cout << "Enter the two items from the menu: " << std::endl;
  std::cout << "Enter the first item: " << std::endl;
  std::getline(std::cin, item1);
  std::cout << "Enter the second item: " << std::endl;
  std::getline(std::cin, item2);

  menu_total = menu_map[item1] + menu_map[item2];

  std::cout << std::endl;
  std::cout << "Total Amount of the order:  " <<  menu_total;
  return 0;
}
