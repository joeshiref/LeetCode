class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        vector<int>vec;
        for(auto num:queries)
        {
            int idx = upper_bound(nums.begin(),nums.end(),num)-nums.begin();
            vec.push_back(idx);
        }
        return vec;
    }
};