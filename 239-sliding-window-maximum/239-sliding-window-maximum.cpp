class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int len=0;
        map<int,int>mp;
        vector<int>ans;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            len++;
            if(len==k)
            {
                auto itmax = mp.end();
                itmax--;
                ans.push_back(itmax->first);
                mp[nums[i-k+1]]--;
                if (mp[nums[i - k + 1]] == 0)
                    mp.erase(nums[i - k + 1]);
                len--;
            }
        }
        return ans;
    }
};