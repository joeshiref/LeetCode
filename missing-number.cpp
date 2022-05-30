class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=n,cur=0;
        for(int i=0;i<n;i++)
        {
            if(cur!=nums[i])
            {
                ans=cur;
                break;
            }
            cur++;
        }
        return ans;
    }
};