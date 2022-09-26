class Solution {
public:
    int DP[13][10001];
    int solve(int idx,int rem,vector<int>& coins)
    {
        if(rem == 0)
            return 0;
        if(idx<0 || rem<=0)
            return INT_MAX - 1;
        if(DP[idx][rem]!=-1)
            return DP[idx][rem];
        int ch1 = solve(idx-1,rem,coins);
        int ch2 = solve(idx,rem-coins[idx],coins)+1;
        return DP[idx][rem]=min(ch1, ch2);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        memset(DP,-1,sizeof(DP));
        int ans = solve(coins.size()-1,amount,coins);
        return ans==(INT_MAX - 1)?-1:ans;
    }
};