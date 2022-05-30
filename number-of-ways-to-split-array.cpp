class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>pre;
        pre.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            pre.push_back(pre[i-1]+nums[i]);
        long long sum=pre[pre.size()-1];
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            long long v=pre[i];
            if(v>=sum-v)
                cnt++;
        }
        return cnt;
    }
};