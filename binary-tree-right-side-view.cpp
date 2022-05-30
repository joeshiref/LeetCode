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
    vector<int>ans;
    map<TreeNode*,bool> vis;
    void doWork(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        vis[root]=true;
        int sz;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            sz=q.size();
            while(sz--)
            {
                TreeNode*cur=q.front();
                q.pop();
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
            }
        }
        
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return ans;
        doWork(root);
        return ans;
    }
};