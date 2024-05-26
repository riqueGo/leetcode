#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || p == root || q == root)
            return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;
    }
};


int main()
{
    TreeNode* p = new TreeNode(4);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2, nullptr, p);
    q->right = new TreeNode(3);
    Solution solution;
    solution.lowestCommonAncestor(q,p,q->right);
}