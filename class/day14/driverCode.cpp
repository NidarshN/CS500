#include "charstack.h"
#include <iostream>

int main()
{

    CharStack stack;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Peak: " << stack.peek() << std::endl;

    stack.push('e');
    stack.push('m');
    stack.push('o');
    stack.push('h');

    std::cout << "Size: " << stack.size() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Peak: " << stack.peek() << std::endl;
    std::cout << "Pop: " << stack.pop() << std::endl;

    stack.clear();
    
    std::cout << "Pop: " << stack.pop() << std::endl;
    std::cout << "Peak: " << stack.peek() << std::endl;
    std::cout << "Is Stack Empty?: " << ((stack.isEmpty() == 1 ) ? "Yes" : "No") << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;
}