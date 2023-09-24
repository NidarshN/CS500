#include <iostream>
#include "deque.h"

/*
class Deque{

private:
  struct Node{
    int val;
    Node* prevNode;
    Node* nextNode;
 

    Node(Node* prev, int value, Node* next){
        prevNode = prev;
        val = value;
        nextNode = next;
    }
  };
  
  Node* startOfQueue;
  Node* endOfQueue;

public:*/
  Deque::Deque(){
    startOfQueue = nullptr;
    endOfQueue = nullptr;
  }

bool Deque::is_empty(){
    return (getStartOfQueue() == nullptr);
  }

  Deque::Node* Deque::getStartOfQueue(){
    return startOfQueue;
  }

  void Deque::setStartOfQueue(Node* n){
    startOfQueue = n;
  }

  void Deque::push_front(int i){
    Deque::Node* newNode = new Deque::Node(nullptr, i, getStartOfQueue());
    if(is_empty()){
      setEndOfQueue(newNode);
    }else{
      getStartOfQueue()->prevNode = newNode;
    }
    setStartOfQueue(newNode);
    
  }

  int Deque::pop_front(){
    if(!is_empty()){
      int val = getStartOfQueue()->val;
      Deque::Node* newStart = getStartOfQueue()->nextNode;
      delete getStartOfQueue();
      setStartOfQueue(newStart);

      if(getStartOfQueue() == nullptr) setEndOfQueue(nullptr);

      return val;
    }
    std::cout << "Error: Tried popping an empty deque!" << std::endl;
    return 0;
  }

  int Deque::peak_front(){
    if(!is_empty()) return getStartOfQueue()->val;
    std::cout << "Error: Tried to peak into an empty deque!" << std::endl;
    return 0;
  }

  Deque::Node* Deque::getEndOfQueue(){
    return endOfQueue;
  }

  void Deque::setEndOfQueue(Node* n){
    endOfQueue = n;
  }

  void Deque::push_back(int i){
    Deque::Node* newNode = new Deque::Node(getEndOfQueue(), i, nullptr);
    if(is_empty()){
      setStartOfQueue(newNode);
    }else{
      getEndOfQueue()->nextNode = newNode;
    }
    setEndOfQueue(newNode);
  }

  int Deque::pop_back(){
    if(!is_empty()){
      int val = getEndOfQueue()->val;
      Deque::Node* newEnd = getEndOfQueue()->prevNode;
      delete getEndOfQueue();
      setEndOfQueue(newEnd);
      if(getEndOfQueue() == nullptr){
	setStartOfQueue(nullptr);
      }else{
	getEndOfQueue()->nextNode = nullptr;
      }
      return val;
    }
    std::cout << "Error: Tried popping an empty deque!" << std::endl;
    return 0;
  }

  int Deque::peak_back(){
    if(!is_empty()) return getEndOfQueue()->val;
    std::cout << "Error: Tried to peak into an empty deque!" << std::endl;
    return 0;
  }

  void Deque::remove_all(){
    while(!is_empty()){
      pop_front();
    }
  }

  void Deque::peak_all(){
    Deque::Node* pTraverse = getStartOfQueue();
    while(pTraverse != nullptr){
      std::cout <<pTraverse->val << "\t";
      pTraverse = pTraverse->nextNode;
    }
    std::cout << std::endl;
  }

  Deque::~Deque(){
    remove_all();
  }


//};
