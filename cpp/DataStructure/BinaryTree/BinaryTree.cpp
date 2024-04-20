#include <iostream>

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int val) : data(val), right(nullptr), left(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    bool isEmpty() { return root == nullptr; }

    Node* getRoot() { return root; }

    void insert(int val) {
        Node* newNode = new Node(val);

        if(isEmpty()) {
            root = newNode;
            return;
        }

        Node* currNode = root;
        Node* parentNode;

        while ( currNode != nullptr ) {
            parentNode = currNode;

            if(newNode->data > currNode->data) {
                currNode = currNode->right;
            }else{
                currNode = currNode->left;
            }
        }

        if(newNode->data > parentNode->data){
            parentNode->right = newNode;
        }else{
            parentNode->left = newNode;
        }
    }

    void printTree(Node* node) {
        if (node == nullptr) {
            return;
        }

        printTree(node->left);
        printTree(node->right);
        std::cout << node->data << " ";
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }

        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
};

int main() {
    BinaryTree bTree;

    bTree.insert(9);
    bTree.insert(12);
    bTree.insert(17);
    bTree.insert(13);
    bTree.insert(15);
    bTree.insert(7);
    bTree.insert(4);
    bTree.insert(8);
    bTree.printTree(bTree.getRoot());
    std::cout << std::endl;
    bTree.inOrderTraversal(bTree.getRoot());
    std::cout << std::endl;
}
