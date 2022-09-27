/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>values,prefix;
    int sum;
    void inOrderTraverse(TreeNode* root)
    {
        if(root==NULL)
            return;
        inOrderTraverse(root->left);
        values.push_back(root->val);
        inOrderTraverse(root->right);
    }
    void changeValues(TreeNode*root)
    {
        if(root==NULL)
            return;
        changeValues(root->right);
        int totalSum = root->val + sum;
        sum += root->val;
        root->val = totalSum;
        changeValues(root->left);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return NULL;

        TreeNode * cur = root;
        changeValues(cur);
        return root;
    }
};