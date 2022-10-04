class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &num:nums)
        {
            st.insert(num);
        }
        return nums.size()>st.size();
    }
};