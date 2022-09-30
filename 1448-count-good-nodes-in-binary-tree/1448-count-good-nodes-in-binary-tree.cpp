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
    void findGood(TreeNode* root, int maxSofar,int &cnt)
    {
        if(root==NULL)
            return;
        if(root->val>=maxSofar)
            cnt++;
        findGood(root->left,max(maxSofar,root->val),cnt);
        findGood(root->right,max(maxSofar,root->val),cnt);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        findGood(root,root->val,cnt);
        return cnt;
    }
};