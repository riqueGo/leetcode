#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
class Queue {
    private:
        Node<T>* _front;
        Node<T>* _back;
        int _size;

    public:
        Queue() : _front(nullptr), _back(nullptr), _size(0) {}

        bool isEmpty() const { return _front == nullptr; }

        int size() const { return _size; }

        T front() {
            if(isEmpty()){ throw std::runtime_error("Queue is empty"); }
            return _front->data;
        }

        T back() {
            if(isEmpty()){ throw std::runtime_error("Queue is empty"); }
            return _back->data;
        }

        void push_back(T value) {
            Node<T>* newNode = new Node<T>(value);

            if(isEmpty()){
                _front = _back = newNode;
            } else {
                _back->next = newNode;
                _back = newNode;
            }

            _size++;
        }

        T pop_front() {
            if(isEmpty()) { throw std::runtime_error("Queue is Empty"); }

            Node<T>* temp = _front;
            _front = _front->next;

            if(isEmpty()) {
                _back = nullptr;
            }

            T val = temp->data;
            _size--;

            delete temp;
            return val;
        }
        void print() const {
            if(isEmpty()) {
                std::cout << "[]" << std::endl;
                return;
            }

            std::cout << "[" << _front->data;

            Node<T>* curr = _front->next;
            while(curr != nullptr) {
                std::cout << "," << curr->data;
                curr = curr->next;
            }
            std::cout << "]" << std::endl;
        }

        ~Queue() {
            while(!isEmpty()) {
                pop_front();
            }
        }
};

int main() {
    Queue<int> myQueue;

    myQueue.push_back(1);
    myQueue.push_back(2);
    myQueue.push_back(3);

    std::cout << "Front element: " << myQueue.front() << std::endl;

    myQueue.print();

    while(!myQueue.isEmpty()){
        std::cout << "Dequeue: " << myQueue.pop_front() << std::endl;
    }

    myQueue.print();
}
