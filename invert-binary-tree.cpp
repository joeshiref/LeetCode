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
    void doWork(TreeNode *source)
    {
        if(source==NULL)
            return;
        TreeNode * tmp=source->left;
        source->left=source->right;
        source->right=tmp;
        if(source->left!=NULL)
            doWork(source->left);
        if(source->right!=NULL)
            doWork(source->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *cur=root;
        doWork(cur);
        return root;
    }
};