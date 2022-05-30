class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int val=nums[i];
            if(val>ans[ans.size()-1])
                ans.push_back(val);
            else
            {
                int idx=lower_bound(ans.begin(),ans.end(),val)-ans.begin();
                ans[idx]=val;
            }
        }
        return ans.size();
        
    }
};