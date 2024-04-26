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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode*> nodes;
        nodes.push(root);

        TreeNode* currNode;

        int levelSize;

        while (!nodes.empty())
        {
            levelSize = nodes.size();
            vector<int> levelNodes(levelSize);

            for(int i = 0; i < levelSize; i++)
            {
                currNode = nodes.front();
                nodes.pop();
                levelNodes[i] = currNode->val;

                if (currNode->left != nullptr)
                    nodes.push(currNode->left);
                if (currNode->right != nullptr)
                    nodes.push(currNode->right);
            }
            result.push_back(levelNodes);
        }
        return result;
    }
};