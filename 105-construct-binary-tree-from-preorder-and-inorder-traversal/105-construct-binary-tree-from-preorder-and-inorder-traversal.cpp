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
    unordered_map<int,int>mp;
    int idx;
    TreeNode* rec(int left, int right, vector<int>& preorder, vector<int>& inorder)
    {
        if(left>right)
            return NULL;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        root->left = rec(left,mp[val]-1,preorder,inorder);
        root->right = rec(mp[val]+1,right,preorder,inorder);
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        idx=0;
        return rec(0,inorder.size()-1,preorder,inorder);
    }
};