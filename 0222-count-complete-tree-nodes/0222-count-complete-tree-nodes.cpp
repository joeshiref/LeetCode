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
    int leftHeight(TreeNode* root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode* root)
    {
        int cnt = 0;
        while(root)
        {
            cnt++;
            root=root->right;
        }
        return cnt;
    }
    
    int solve(TreeNode * root)
    {
        if(!root)
            return 0;
        int lh=leftHeight(root);
        int rh=rightHeight(root);
        if(lh==rh)
            return (1<<lh)-1;
        return 1 + solve(root->left)
           + solve(root->right);
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};