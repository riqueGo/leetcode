#include <iostream>
#include <algorithm>

using std::min;

class Node {
public:
    int data;
    int min;
    Node* next;

    Node(int val, int min) : data(val), min(min), next(nullptr) {}
};

class MinStack {
private:
    Node* _top;

public:
    MinStack() : _top(nullptr) {}

    bool isEmpty() { return _top == nullptr; }
    
    void push(int val) {
        Node* newNode;

        if(isEmpty()){
            newNode = new Node(val, val);
            _top = newNode;
        } else {

            newNode = new Node(val, min(val, this->getMin()));
            newNode->next = _top;
            _top = newNode;
        }

    }
    
    void pop() {
        _top = _top->next;
    }
    
    int top() { return _top->data; }
    
    int getMin() { return _top->min; }
};