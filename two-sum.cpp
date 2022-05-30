class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int> >mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int rem=target-nums[i];
            if(mp[rem].size())
            {
                if(rem==nums[i])
                {
                    if(mp[rem].size()>1)
                    {
                        ans.push_back(mp[rem][0]);
                        ans.push_back(mp[rem][1]);
                        return ans;
                    }
                }
                else
                {
                    ans.push_back(mp[rem][0]);
                    ans.push_back(mp[nums[i]][0]);
                    return ans;

                }
            }
        }
        return ans;
    }
    
};