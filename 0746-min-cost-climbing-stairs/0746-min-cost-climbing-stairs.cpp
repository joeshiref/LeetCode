class Solution {
public:
    int dp[1010];
    int solve(int idx,vector<int>& cost)
    {
        if(idx>=cost.size())
            return 0;
        int & ret = dp[idx];
        if(~ret)
            return ret;
        int ch1 = solve(idx+1,cost)+cost[idx];
        int ch2 = solve(idx+2,cost)+cost[idx];
        return ret = min(ch1,ch2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min(solve(0,cost),solve(1,cost));
    }
};