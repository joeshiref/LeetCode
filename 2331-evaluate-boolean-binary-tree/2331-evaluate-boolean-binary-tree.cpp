class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr and root->right == nullptr) 
            return root->val;
        

        bool evaluateLeftSubtree = evaluateTree(root->left);
        bool evaluateRightSubtree = evaluateTree(root->right);
        bool evaluateRoot;
        if (root->val == 2) 
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        else 
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;

        return evaluateRoot;
    }
};