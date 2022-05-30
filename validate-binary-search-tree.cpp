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
    
    bool flag,ans;
    int preValue;
    void doWork(TreeNode *root)
    {
        if(root==NULL)
            return;
        doWork(root->left);
        if(!flag)
        {
            preValue=root->val;
            flag=true;
        }
        else
        {
            ans=ans && preValue<root->val;
            preValue=root->val;
        }
        doWork(root->right);
        
        
    }
    
    bool isValidBST(TreeNode* root) {
        flag=false;
        ans=true;
        doWork(root);
        return ans;
    }
};