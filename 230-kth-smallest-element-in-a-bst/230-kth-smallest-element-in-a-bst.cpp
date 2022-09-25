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
    priority_queue<int>pq;
    
    void traverse(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        if(pq.size()==k)
        {
            if(pq.top()>root->val)
            {
                pq.pop();
                pq.push(root->val);
            }
        }
        else
            pq.push(root->val);
        traverse(root->left, k);
        traverse(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return pq.top();
    }
};