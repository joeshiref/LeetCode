class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // try unordered
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        
        for(auto num:nums)
        {
            int rem = target - num;
            if(mp[rem].size())
            {
                if(rem==num)
                {
                    if(mp[rem].size()>1)
                        return {mp[rem][0],mp[rem][1]};
                }
                else
                {
                    return {mp[num][0],mp[rem][0]};
                }
            }
        }
        return {};
    }
};