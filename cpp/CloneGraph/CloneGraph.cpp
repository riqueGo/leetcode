#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using std::vector;
using std::queue;
using std::unordered_map;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (node == NULL) return NULL;

        unordered_map<Node*, Node*> umap;
        umap[node] = new Node(node->val);

        queue<Node*> nodes;
        nodes.push(node);

        while (!nodes.empty())
        {
            Node* currNode = nodes.front();
            nodes.pop();

            for (Node* neighbor : currNode->neighbors)
            {
                if (umap.find(neighbor) == umap.end())
                {
                    umap[neighbor] = new Node(neighbor->val);
                    nodes.push(neighbor);
                }

                umap[currNode]->neighbors.push_back(umap[neighbor]);
            }
        }
        return umap[node];
    }
};


int main()
{
    Node node1(1), node2(2), node3(3), node4(4);
    node1.neighbors.push_back(&node2);
    node1.neighbors.push_back(&node4);
    node2.neighbors.push_back(&node1);
    node2.neighbors.push_back(&node3);
    node3.neighbors.push_back(&node2);
    node3.neighbors.push_back(&node4);
    node4.neighbors.push_back(&node1);
    node4.neighbors.push_back(&node3);

    Solution solution;
    solution.cloneGraph(&node1);
}