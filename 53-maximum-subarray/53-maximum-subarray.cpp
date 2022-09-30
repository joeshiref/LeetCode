class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0, mx=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            curSum+=nums[i];
            if(curSum>mx)
                mx=curSum;
            if(curSum<0)
                curSum = 0;
        }
        return mx;
    }
};