class Solution {
public:
    
    vector<vector<int>>ret;
    vector<int>ans;
    
    void BT(int idx, int currentSum, int target, vector<int>&nums)
    {
        if(idx==nums.size() || currentSum>target)
            return;
        if(currentSum==target)
        {
            ret.push_back(ans);
            return;
        }
        if(currentSum+nums[idx]<=target)
        {
            ans.push_back(nums[idx]);
            BT(idx,currentSum+nums[idx],target,nums);
            ans.pop_back();
        }
        BT(idx+1,currentSum,target,nums);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        BT(0,0,target,candidates);
        return ret;
    }
};