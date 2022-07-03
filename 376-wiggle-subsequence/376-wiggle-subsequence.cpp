class Solution {
public:
    int DP[1001][4];
    int solve(int idx,int prev,vector<int>& nums)
    {
        if(idx==nums.size())
            return 0;
        if(DP[idx][prev]!=-1)
            return DP[idx][prev];
        int ch1=solve(idx+1,prev,nums);
        int ch2=0;
        if(prev<3)
        {
            if(nums[idx]>0 && (prev==0||prev==2))
                ch2=solve(idx+1,1,nums)+1;
            else if(nums[idx]<0 && (prev==1||prev==2))
                ch2=solve(idx+1,0,nums)+1;
        }
        return DP[idx][prev]=max(ch1,ch2);
    }
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>v;
        for(int i=1;i<nums.size();i++)
            v.push_back(nums[i]-nums[i-1]);    
        int cnt=0,prev=2;
         for(auto num:v)
         {
             if(num>0 && (prev==0||prev==2))
             {
                 cnt++;
                 prev=1;
             }
             else if(num<0 && (prev==1||prev==2))
             {
                 cnt++;
                 prev=0;
             }
         }
        return cnt+1;
        
    }
};