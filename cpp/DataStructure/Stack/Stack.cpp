#include <iostream>

// Node class for holding data
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
    private:
        Node<T>* _top;
        int _size;
    
    public:
        Stack() : _top(nullptr), _size(0) {}

        bool isEmpty() const { return _top == nullptr; }

        int size() const { return _size; }

        T top() const { 
            if(isEmpty()){
                throw std::runtime_error("Stack is empty");
            }
            return _top->data;
        }

        void push(T value) {
            Node<T>* newNode = new Node<T>(value);

            if(isEmpty()){
                _top = newNode;
            } else {
                newNode->next = _top;
                _top = newNode;
            }

            _size++;
        }

        T pop() {
            if(isEmpty()){
                throw std::runtime_error("Stack is empty");
            }

            Node<T>* temp = _top;
            _top = _top->next;
            T value = temp->data;

            _size--;

            delete temp;
            return value;
        }

        ~Stack() {
            while(!isEmpty()){
                pop();
            }
        }

};

int main() {
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.top() << std::endl;

    while (!myStack.isEmpty()) {
        std::cout << "Popped: " << myStack.pop() << std::endl;
    }

    return 0;
}
