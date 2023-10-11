#include <iostream>
#include <string>
#include "charstack.h"


CharStack::CharStack(){
  top = nullptr;
  sizeOfStack = 0;
}


CharStack::~CharStack(){
  clear();
}


int CharStack::size(){
  return sizeOfStack;
}

bool CharStack::isEmpty(){
  return sizeOfStack == 0;
}

void CharStack::clear(){
  while(top != nullptr){
    char temp = pop();
  }
  sizeOfStack = 0;
}

void CharStack::push(char ch){
  Node* newNode = new Node(ch, top);
  setTop(newNode);
}

char CharStack::pop(){
  if(top != nullptr){
    char temp = top->val;
    Node* newTop = top->nextNode;

    delete top;
    --sizeOfStack;
    setTop(newTop);
    return temp;
  }
  std::cout << "Error: Tried popping an empty stack!" << std::endl;
  return 0;
}

char CharStack::peek(){
  if(top != nullptr) return top->val;
  std::cout << "Error: Tried peek an empty stack!" << std::endl;
  return 0;
}

void CharStack::setTop(Node* n){
  top = n;
  ++sizeOfStack;
}
