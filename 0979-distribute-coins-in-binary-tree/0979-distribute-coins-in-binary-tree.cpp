class Solution {
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }
private:
    int moves;
    int dfs(TreeNode* current) {
        if (current == nullptr) return 0;

        int leftCoins = dfs(current->left);
        int rightCoins = dfs(current->right);

        moves += abs(leftCoins) + abs(rightCoins);

        return (current->val - 1) + leftCoins + rightCoins;
    }
};