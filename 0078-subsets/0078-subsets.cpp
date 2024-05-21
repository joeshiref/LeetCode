class Solution {
public:
    
    vector<vector<int> >st;
    vector<int>vec;
    
    void solve(int idx, vector<int>& nums)
    {
        if(idx==nums.size())
        {
            st.push_back(vec);
            return;
        }
        solve(idx+1,nums);
        vec.push_back(nums[idx]);
        solve(idx+1,nums);
        vec.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        
        return st;
    }
};