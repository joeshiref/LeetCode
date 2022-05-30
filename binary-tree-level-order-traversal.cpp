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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> >v;
        if(root==NULL)
            return v;
        queue<TreeNode*>q;
        q.push(root);
        int sz;
        while(!q.empty())
        {
            sz=q.size();
            vector<int>tmp;
            while(sz--)
            {
                TreeNode*cur=q.front();
                tmp.push_back(cur->val);
                q.pop();
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
            v.push_back(tmp);
        }
        return v;
    }
};