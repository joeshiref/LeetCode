class Solution {
public:
    
    vector<int>DP;
    int solve(int idx, vector<int>& nums)
    {
        if(idx>=nums.size())
            return 0;
        int & ret = DP[idx];
        if(ret!=-1)
            return ret;
        int ch1 = solve(idx+2,nums)+nums[idx];
        int ch2 = solve(idx+1,nums);
        return ret=max(ch1,ch2);
        
    }
    
    int rob(vector<int>& nums) {
        DP = vector<int>(nums.size(),-1);
        return solve(0,nums);
    }
};