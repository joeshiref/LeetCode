class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int> >mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(mp[rem].size())
            {
                if(rem!=nums[i])
                    return {i,mp[rem][0]};
                else
                {
                    int idxOfCur=lower_bound(mp[rem].begin(),mp[rem].end(),i)-mp[rem].begin();
                    if(mp[rem].size()>1)
                        return {i,mp[rem][idxOfCur+1]};
                }
            }
            
        }
        return {};
    }
};