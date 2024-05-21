class Solution {
public:
    
    set<vector<int> >st;
    vector<int>vec;
    
    void solve(int idx, vector<int>& nums)
    {
        if(idx==nums.size())
        {
            st.insert(vec);
            return;
        }
        solve(idx+1,nums);
        vec.push_back(nums[idx]);
        solve(idx+1,nums);
        vec.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        vector<vector<int>> ans;
        for(auto v:st)
            ans.push_back(v);
        return ans;
    }
};