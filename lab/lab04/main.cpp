#include <iostream>
#include "deque.h"

int main(){
  Deque d;

  d.push_front(5);
  d.push_back(10);
  d.push_front(15);
  d.push_back(20);

  d.peak_all();

  std::cout << "PF: " << d.pop_front() << std::endl;
  std::cout << "PB: " << d.pop_back() << std::endl;
  std::cout << "PeF: " << d.peak_front() << std::endl;
  std::cout << "PeB: " << d.peak_back() << std::endl;

  d.remove_all();

  d.peak_all();

}
