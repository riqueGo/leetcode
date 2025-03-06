#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int k, bads[26], count = 0;

class Node {
public:
    Node* children[26];

    Node() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class SuffixTrie {
private:
    Node* root;

    void insertSuffix(const string& suffix) {
        Node* current = root;
        int badCount = k;
        for (char ch : suffix) {
            int index = ch - 'a';

            if(!bads[index]) {
                badCount--;
            }

            if(badCount < 0) {
                break;
            }

            if (!current->children[index]) {
                current->children[index] = new Node();
                count++;
            }
            current = current->children[index];
        }
    }

public:
    SuffixTrie(const string& text) {
        root = new Node();
        for (int i = text.size() - 1, l = 1; i >= 0; i--, l++) {
            insertSuffix(text.substr(i,l));
        }
    }
};


int main() {
    string s;
    cin >> s;

    char ch;
    for(int i = 0; i < 26; i++) {
        cin >> ch;
        bads[i] = ch - '0';
    }

    cin >> k;


    SuffixTrie trie(s);
    cout << count << endl;
}