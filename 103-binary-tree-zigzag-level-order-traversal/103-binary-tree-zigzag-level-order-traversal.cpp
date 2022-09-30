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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>>ans;
        queue<TreeNode*>que;
        que.push(root);
        int sz,level=0;
        
        while(!que.empty())
        {
            sz = que.size();
            vector<int>tmp(sz);
            for(int i=0;i<sz;i++)
            {
                TreeNode* cur = que.front();
                int idx = (level)==0?i:(sz-1-i);
                tmp[idx]=cur->val;
                que.pop();
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            
            ans.push_back(tmp);
            level^=1;
        }
        
        
        
        return ans;
    }
};