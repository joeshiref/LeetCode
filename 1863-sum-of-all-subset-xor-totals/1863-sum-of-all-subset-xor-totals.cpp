class Solution {
public:
    
    vector<int>vec;
    int sum;
    int getResult(vector<int>arr)
    {
        int res = 0;
        for(auto num:arr)
            res^=num;
        return res;
    }
    void solve(int idx, vector<int>&nums)
    {
        if(idx==nums.size())
        {
            sum+=getResult(vec);
    
            return;
        }
        solve(idx+1,nums);
        vec.push_back(nums[idx]);
        solve(idx+1,nums);
        vec.pop_back();
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        solve(0,nums);
        return sum;
    }
};