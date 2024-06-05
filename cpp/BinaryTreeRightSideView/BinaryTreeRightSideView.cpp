#include<iostream>
#include<vector>
#include<queue>

using std::vector;
using std::queue;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> nodeQueue;
        
        if(root == NULL)
            return result;

        nodeQueue.push(root);
        int countNodesInLevel = 1;
        TreeNode* currNode;

        while(!nodeQueue.empty())
        {
            currNode = nodeQueue.front();
            nodeQueue.pop();
            countNodesInLevel--;

            if(currNode->left != NULL)
                nodeQueue.push(currNode->left);
            
            if(currNode->right != NULL)
                nodeQueue.push(currNode->right);

            if(countNodesInLevel == 0)
            {
                result.push_back(currNode->val);
                countNodesInLevel = nodeQueue.size();
            }
        }
        return result;
    }
};