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
    
    vector<double> BFS(TreeNode* root)
    {
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        int sz=1;
        while(!q.empty())
        {
            sz=q.size();
            int tmpsz=sz;
            double sum=0;
            while(sz--)
            {
                TreeNode*cur=q.front();
                q.pop();
                sum+=(cur->val);
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
            }
            ans.push_back(sum/tmpsz);
        }
        return ans;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        return BFS(root);
    }
};