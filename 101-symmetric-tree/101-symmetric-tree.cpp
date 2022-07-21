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
    bool flag=true;
    
    void rec(TreeNode* left,TreeNode* right)
    {
        if(left==NULL && right==NULL)
            return;
        if((left==NULL && right!=NULL) || (left!=NULL && right==NULL) || left->val != right->val)
        {
            flag=false;
            return;
        }
        rec(left->left,right->right);
        rec(left->right,right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        rec(root->left,root->right);
        return flag;
    }
};