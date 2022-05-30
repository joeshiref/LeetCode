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

class Solution
{
public:
    map<int,int>mp;

    TreeNode* solve(int s,int e,int &cur,vector<int>& inorder, vector<int>& postorder)
    {
        if(s>e)
            return NULL;
        TreeNode* root = new TreeNode(postorder[cur]);
        int idx=mp[postorder[cur]];
        cur--;
        root->right=solve(idx+1,e,cur,inorder,postorder);
        root->left=solve(s,idx-1,cur,inorder,postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {

        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]]=i;
        }
        int curIdx=inorder.size()-1;
        return solve(0,curIdx,curIdx,inorder,postorder);

    }
};