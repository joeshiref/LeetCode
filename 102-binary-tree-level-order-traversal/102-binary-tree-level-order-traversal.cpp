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
    vector<vector<int>> res;
    void bfs(TreeNode* root)
    {
        queue<TreeNode*>q;
        q.push(root);
        int sz;
        while(!q.empty())
        {
            sz=q.size();
            vector<int>tmp;
            while(sz--)
            {
                TreeNode* cur = q.front();
                q.pop();
                cout << cur->val << " ";
                tmp.push_back(cur->val);
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
            cout << endl;
            res.push_back(tmp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        bfs(root);
        return res;
    }
};