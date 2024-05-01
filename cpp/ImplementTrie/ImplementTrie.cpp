#include<iostream>
#include<vector>

using std::string;
using std::vector;

struct Node
{
    Node* nodes [26] = {};
    bool isEnd = false;
};


class Trie
{
    private:
        Node* root;

    public:
        Trie() {
            root = new Node;
        }
        
        void insert(string word) {
            Node* currNode = root;
            Node* tempNode;

            for (int i = 0; i < word.size(); i++)
            {
                tempNode = currNode->nodes[word.at(i) - 'a'];
                if (tempNode == NULL)
                {
                    tempNode = new Node;
                    currNode->nodes[word.at(i) - 'a'] = tempNode;
                }
                currNode = tempNode;
            }

            currNode->isEnd = true;
        }
        
        bool search(string word) {
            Node* currNode = root;
            
            for (int i = 0; i < word.size(); i++)
            {
                currNode = currNode->nodes[word.at(i)-'a'];
                if (currNode == NULL)
                    return false;
            }
            return currNode->isEnd;
        }
        
        bool startsWith(string prefix) {
            Node* currNode = root;
            
            for (int i = 0; i < prefix.size(); i++)
            {
                currNode = currNode->nodes[prefix.at(i)-'a'];
                if (currNode == NULL)
                    return false;
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bag");
}