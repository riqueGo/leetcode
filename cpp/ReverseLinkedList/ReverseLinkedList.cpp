#include <iostream>
#include <cstddef>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int data ) {
        this->data = data;
    }
};

class Solution {
public:
    SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
        SinglyLinkedListNode* prev = NULL;
        SinglyLinkedListNode* temp = NULL;
        SinglyLinkedListNode* curr = llist;
        
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }

};

int main() {
    SinglyLinkedListNode first(1);
    SinglyLinkedListNode second(2);
    SinglyLinkedListNode third(3);
    SinglyLinkedListNode fourth(4);
    SinglyLinkedListNode fifth(5);
    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &fifth;
    fifth.next = NULL;
    
    Solution s;
    s.reverse(&first);
}