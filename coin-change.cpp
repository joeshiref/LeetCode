class Solution {
public:
    int DP[13][10002];
    long long doWork(int idx,int rem,vector<int>& coins)
    {
        if(idx>=coins.size() || rem<0)
            return INT_MAX;
        if(rem==0)
            return 0;
        int &ret=DP[idx][rem];
        if(ret!=-1)
            return ret;
        long long ch1=doWork(idx-1,rem,coins);
        long long ch2=doWork(idx,rem-coins[idx],coins)+1;
        return ret=min(ch1,ch2);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(DP,-1,sizeof(DP));
        int ans=doWork(coins.size()-1,amount,coins);
        return ans==INT_MAX?-1:ans;
    }
};