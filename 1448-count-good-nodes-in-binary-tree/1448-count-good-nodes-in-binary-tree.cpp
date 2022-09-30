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
    int solve(TreeNode* root,int mx)
    {
        if(root==NULL)
            return 0;
        int res = (root->val>=mx?1:0);
        res+=solve(root->left,max(mx,root->val));
        res+=solve(root->right,max(mx,root->val));
        return res;
    }
    int goodNodes(TreeNode* root) {
        
        return solve(root,-10001);
    }
};