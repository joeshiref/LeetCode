class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int,int>mp;
        int cnt = 0,sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum == goal)
                cnt++;
            if(mp.find(sum-goal)!=mp.end())
                cnt+=mp[sum-goal];
            mp[sum]++;
        }
        return cnt;
    }
};