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
        changeValues(root->left);
        //values.push_back(root->val);
        int val = root->val;
        int idx = lower_bound(values.begin(),values.end(),val)-values.begin();
        int sumVal = prefix[prefix.size()-1]-prefix[idx];
        root->val = sumVal+val;
        changeValues(root->right);
        
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        inOrderTraverse(root);
        prefix.push_back(values[0]);
        
        for(int i=1;i<values.size();i++)
            prefix.push_back(prefix[i-1]+values[i]);
        
        TreeNode * cur = root;
        changeValues(cur);
        return root;
    }
};