class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax=0,mx=nums[0];
       
        for(int i=0;i<nums.size();i++)
        {
            curMax+=nums[i];
            if(curMax>mx)
                mx=curMax;
            if(curMax<0)
                curMax=0;
        }
        return mx;
    }
};