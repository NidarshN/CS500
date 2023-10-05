#include <iostream>

class Stack{
private:
  struct Node{
    int val;
    Node* nextNode;

    Node(int value, Node* n){
      val = value;
      nextNode = n;
    }

  };

  Node* topOfStack;

public:
  Stack(){
    topOfStack = nullptr;
  }

  Node* getTopOfStack(){
    return topOfStack;
  }

  void setTopOfStack(Node* n){
    topOfStack = n;
  }

  void push(int i){
    Node* newNode = new Node(i, topOfStack);
    setTopOfStack(newNode);
  }

  int pop(){
    if(topOfStack != nullptr){
      int val = topOfStack->val;
      Node* ptrNewTop = topOfStack->nextNode;

      delete topOfStack;
      setTopOfStack(ptrNewTop);
      return val;
    }
    std::cout << "Error: Tried popping an empty stack!" << std::endl;
    return 0;
  }

  int peak(){
    if(topOfStack != nullptr) return topOfStack->val;
    std::cout << "Error: Tried to peak into an empty stack!" << std::endl;
    return 0;
  }

  void removeAll(){
    while(getTopOfStack() != nullptr){
      int temp = pop();
    }
  }

  ~Stack(){
    removeAll();
  }
};


int main(){
  Stack s;
  std::cout << "Pop: " << s.pop() << std::endl;
  std::cout << "Peak: " << s.peak() << std::endl;

  s.push(9);
  s.push(12);
  s.push(45);
  s.push(200);

  std::cout << "Pop: " << s.pop() << std::endl;
  std::cout << "Peak: " << s.peak() << std::endl;
  std::cout << "Pop: " << s.pop() << std::endl;

  s.removeAll();

  std::cout << "Pop: " << s.pop() << std::endl;
  std::cout << "Peak: " << s.peak() << std::endl;
}
