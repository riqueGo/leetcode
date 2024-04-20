#include <iostream>
#include <climits>

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
    int _min;

public:
    MinStack() : _top(nullptr), _min(INT_MAX) {}

    bool isEmpty() { return _top == nullptr; }
    
    void push(int val) {
        Node* newNode;

        if(isEmpty()){
            _min = val;
            newNode = new Node(val, _min);
            _top = newNode;
        } else {
            if (val < _min) { _min = val; }

            newNode = new Node(val, _min);
            newNode->next = _top;
            _top = newNode;
        }

    }
    
    void pop() {
        Node* temp = _top;
        _top = _top->next;
        _min = isEmpty() ? INT_MAX : _top->min;

        delete temp;
    }
    
    int top() { return _top->data; }
    
    int getMin() { return _min; }
};

int main() {
    MinStack minStack;

    // Push some values onto the stack
    minStack.push(3);
    minStack.push(2);
    minStack.push(5);
    minStack.push(1);

    std::cout << "Top element: " << minStack.top() << std::endl; // Output: 1
    std::cout << "Minimum element: " << minStack.getMin() << std::endl; // Output: 1

    minStack.pop(); // Pop the top element

    std::cout << "Top element: " << minStack.top() << std::endl; // Output: 5
    std::cout << "Minimum element: " << minStack.getMin() << std::endl; // Output: 2

    return 0;
}