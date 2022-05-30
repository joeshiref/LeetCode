class Solution {
public:
    int DP[201][20001];
    int n,sum;
    bool solve(int idx,int collect,vector<int>& nums)
    {
        if(idx==n)
            return false;
        if(collect==sum-collect)
            return true;
        int &ret=DP[idx][collect];
        if(ret!=-1)
            return ret;
        return ret=solve(idx+1,collect,nums) | solve(idx+1,collect+nums[idx],nums);
    }
    bool canPartition(vector<int>& nums) {
        memset(DP,-1,sizeof(DP));
        n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        return solve(0,0,nums);
    }
};