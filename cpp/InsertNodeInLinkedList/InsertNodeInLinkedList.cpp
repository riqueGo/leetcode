
struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data) {
        this->data = data;
    }

    SinglyLinkedListNode(int data, SinglyLinkedListNode* next) {
        this->data = data;
        this->next = next;
    }
};

class Solution {
public:
    SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        
        if(position == 0) {
            newNode->next = llist;
            return newNode;
        }
        
        SinglyLinkedListNode* curr = llist;
        for(int i = 1; i < position; i++) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return llist;
    }
};

int main() {
    SinglyLinkedListNode node1(16);
    SinglyLinkedListNode node2(13);
    SinglyLinkedListNode node3(7);
    node1.next = &node2;
    node2.next = &node3;

    Solution s;
    s.insertNodeAtPosition(&node1, 1, 2);
}