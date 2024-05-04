#include<iostream>
#include<vector>

using std::vector;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {

    private:
        vector<int> tree;

    public:
        bool isValidBST(TreeNode* root)
        {
            dfs(root);
            for(int i = 1; i < tree.size(); i++)
            {
                if (tree.at(i-1) >= tree.at(i))
                    return false;
            }
            return true;
        }

        void dfs(TreeNode* root)
        {
            if(root == nullptr)
                return;

            dfs(root->left);
            tree.push_back(root->val);
            dfs(root->right);
        }
};