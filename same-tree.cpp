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
    bool valid;
    
    void doWork(TreeNode* p, TreeNode* q)
    {
        if((p==NULL && q==NULL))
            return;
        if( (p==NULL && q!=NULL)|| (p!=NULL && q==NULL) || (p->val != q->val))
        {
            valid = false;
            return;
        }
        doWork(p->left,q->left);
        doWork(p->right,q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        valid=true;
        doWork(p,q);
        return valid;
    }
};