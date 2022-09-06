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
	TreeNode* tree;
	int containsOne(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		bool ch1 = containsOne(root->right);
		bool ch2 = containsOne(root->left);
		if (ch1 == 0)
			root->right = NULL;
		if (ch2 == 0)
			root->left = NULL;
		return root->val==1 || ch1 || ch2;
	}
	TreeNode* pruneTree(TreeNode* root) {
        
            return containsOne(root)?root:NULL;
		
	}
};
