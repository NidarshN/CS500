#ifndef _DEQUE_H
#define _DEQUE_H

class Deque {
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

public:
    Deque();

    bool is_empty();
    Node* getStartOfQueue();
    void setStartOfQueue(Node* n);

    void push_front(int i);
    int pop_front();
    int peak_front();

    Node* getEndOfQueue();
    void setEndOfQueue(Node* n);

    void push_back(int i);
    int pop_back();
    int peak_back();

    void remove_all();
    void peak_all();

    ~Deque();
};

#endif
