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
    
    int heightOfTree(TreeNode*source)
    {
        if(source==NULL)
            return 0;
        int left = heightOfTree(source->left);
        int right = heightOfTree(source->right);
        return max(left,right)+1;
    }
    
    int calSum(TreeNode* source,int level)
    {
        if(source==NULL)
            return 0;
        if(level==1)
            return source->val;
        return calSum(source->left,level-1)+calSum(source->right,level-1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        int height = heightOfTree(root);
        return calSum(root,height);
    }
};