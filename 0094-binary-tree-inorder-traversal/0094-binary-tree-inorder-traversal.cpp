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
    
    void run(TreeNode *root, vector<int>&vec)
    {
        if(!root)
            return;
        run(root->left,vec);
        vec.push_back(root->val);
        run(root->right,vec);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        run(root,ans);
        return ans;
    }
};