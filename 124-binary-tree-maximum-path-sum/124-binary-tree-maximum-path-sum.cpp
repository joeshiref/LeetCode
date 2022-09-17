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
    int mx;
    
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left = max(solve(root->left),0);
        int right = max(solve(root->right),0);
        mx = max(mx, left+right+root->val);
        return max(left,right)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        mx=INT_MIN;
        solve(root);
        return mx;
    }
};