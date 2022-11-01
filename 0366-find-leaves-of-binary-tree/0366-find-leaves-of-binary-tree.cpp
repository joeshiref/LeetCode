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
    
    map<TreeNode*,bool>leaves;
    
    vector<int> DFS(TreeNode*root)
    {
        vector<int>level;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* cur = st.top();
            st.pop();
            if((!cur->left && !cur->right) || (cur->left && !cur->right && leaves[cur->left]) ||
              (!cur->left && cur->right && leaves[cur->right]) || (cur->left && cur->right && leaves[cur->right] && leaves[cur->left]))
            {
                leaves[cur]=true;
                level.push_back(cur->val);
            }
            if(cur->left && !leaves[cur->left])
                st.push(cur->left);
            if(cur->right && !leaves[cur->right])
                st.push(cur->right);
        }
        return level;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while(!leaves[root])
        {
            ans.push_back(DFS(root));
        }
        return ans;
    }
};