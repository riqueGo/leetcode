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
            inOrder(root);
            for(int i = 1; i < tree.size(); i++)
            {
                if (tree.at(i-1) >= tree.at(i))
                    return false;
            }
            return true;
        }

        void inOrder(TreeNode* root)
        {
            if(root == nullptr)
                return;

            inOrder(root->left);
            tree.push_back(root->val);
            inOrder(root->right);
        }

        bool isValidBST2(TreeNode* root)
        {
            return dfs(root, INT_MIN, INT_MAX);
        }

        bool dfs(TreeNode* root, int left, int right)
        {
            if (!root)
                return true;
            if (root->val < right && root->val > left)
                return dfs(root->left, left, root->val) && dfs(root->right, root->val, right);

            return false;
            
        }

};