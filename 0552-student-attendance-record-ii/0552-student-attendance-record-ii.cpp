class Solution {
    int MOD = 1000000007;
    vector<vector<vector<int>>> memo;

public:
    int eligibleCombinations(int n, int totalAbsences, int consecutiveLates) {

        if (totalAbsences >= 2 or consecutiveLates >= 3) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (memo[n][totalAbsences][consecutiveLates] != -1) {
            return memo[n][totalAbsences][consecutiveLates];
        }
        int count = 0;
        count = eligibleCombinations(n - 1, totalAbsences, 0);
        count = (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
        count = (count + eligibleCombinations(n - 1, totalAbsences, consecutiveLates + 1)) % MOD;

        return memo[n][totalAbsences][consecutiveLates] = count;
    }

    int checkRecord(int n) {
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return eligibleCombinations(n, 0, 0);
    }
};