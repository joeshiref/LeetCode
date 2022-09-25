class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];  
        return max(rob0(nums), rob1(nums));
    }
    int rob0(vector<int>&nums)
    {
        int preMax = 0, curMax = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            int t = curMax;
            curMax = max(preMax + nums[i], curMax);
            preMax = t;  
        }  
      return curMax;
    }
    int rob1(vector<int>&nums)
    {
        int preMax = 0, curMax = 0;
        for(int i = 1; i < nums.size(); i++){
            int t = curMax;
            curMax = max(preMax + nums[i], curMax);
            preMax = t;  
        }  
      return curMax;
    }
};