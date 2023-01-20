class Solution {
public:
    set<vector<int>>ans;
    vector<int> tmp;
    void solve(int idx, vector<int>& nums)
    {
        if(idx == nums.size())
        {
            if(tmp.size()>1)
                ans.insert(tmp);
            return;
        }
        if(tmp.empty() || nums[idx]>=tmp.back())
        {
            tmp.push_back(nums[idx]);
            solve(idx+1,nums);
            tmp.pop_back();
        }
        solve(idx+1,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(0,nums);
        
        return vector(ans.begin(), ans.end());
    }
};