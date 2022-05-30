class Solution {
public:
    int dp[101][2];
    int solve(int idx,bool flag,vector<int>& nums)
    {
        if(idx==nums.size())
            return 0;
        int &ret=dp[idx][flag];
        if(ret!=-1)
            return ret;
        int ch1=solve(idx+1,false,nums);
        int ch2=0;
        if(!flag)
            ch2=solve(idx+1,true,nums)+nums[idx];
        return ret=max(ch1,ch2);
            
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,false,nums);
    }
};