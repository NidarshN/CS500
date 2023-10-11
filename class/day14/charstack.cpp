#include <iostream>
#include <string>
#include "charstack.h"


CharStack::CharStack(){
  top = nullptr;
  sizeOfStack = 0;
}


CharStack::~CharStack(){
  clear();
  delete top;
}


int CharStack::size(){
  return sizeOfStack;
}

bool CharStack::isEmpty(){
  return sizeOfStack == 0;
}

void CharStack::clear(){
  while(getTop() != nullptr){
    char temp = pop();
  }
  sizeOfStack = 0;
}

void CharStack::push(char ch){
  Node* newNode = new Node(ch, top);
  setTop(newNode);
}

char CharStack::pop(){
  if(getTop() != nullptr){
    char temp = getTop()->val;
    Node* newTop = getTop()->nextNode;

    delete getTop();
    --sizeOfStack;
    setTop(newTop);
    return temp;
  }
  std::cout << "Error: Tried popping an empty stack!" << std::endl;
  return 0;
}

char CharStack::peek(){
  if(getTop() != nullptr) return getTop()->val;
  std::cout << "Error: Tried peek an empty stack!" << std::endl;
  return 0;
}

CharStack::Node* CharStack::getTop(){
  return top;
}

void CharStack::setTop(Node* n){
  top = n;
  ++sizeOfStack;
}

