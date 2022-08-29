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
    vector<int>vals;
    
    void traverse(TreeNode* root)
    {
        if(root==NULL)
            return;
        traverse(root->left);
        vals.push_back(root->val);
        traverse(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        
        traverse(root);
        for(int i=1;i<vals.size();i++)
        {
            if(vals[i]<=vals[i-1])
                return false;
        }
        return true;
    }
};