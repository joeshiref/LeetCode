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
            vector<int>tmp;
            while(sz--)
            {
                TreeNode* cur = que.front();
                tmp.push_back(cur->val);
                que.pop();
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
            if(level&1)
                reverse(tmp.begin(),tmp.end());
            ans.push_back(tmp);
            level++;
        }
        
        
        
        return ans;
    }
};