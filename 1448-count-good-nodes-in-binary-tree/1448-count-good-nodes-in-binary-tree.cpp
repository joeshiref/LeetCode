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
    int cnt=0;
    void traverse(TreeNode* root,int maxSoFar)
    {
        if(root==NULL)
            return;
        if(root->val>=maxSoFar)
            cnt++;
        traverse(root->left,max(root->val,maxSoFar));
        traverse(root->right,max(root->val,maxSoFar));
    }
    int goodNodes(TreeNode* root) {
        traverse(root,root->val);
        return cnt;
    }
};