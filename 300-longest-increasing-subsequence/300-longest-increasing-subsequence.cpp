class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            int cur = nums[i];
            if(!i)
                ans.push_back(cur);
            else
            {
                if(cur>ans.back())
                    ans.push_back(cur);
                else
                {
                    int idx = lower_bound(ans.begin(),ans.end(),cur) - ans.begin();
                    ans[idx] = cur;
                }
            }
        }
        return ans.size();
    }
};