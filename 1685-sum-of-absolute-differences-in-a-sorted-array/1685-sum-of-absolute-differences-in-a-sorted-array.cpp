class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre,ans;
        pre.push_back(0);
        for(int i=0;i<n;i++)
        {
            if(!i)
                pre.push_back(nums[i]);
            else
                pre.push_back(nums[i]+pre[i]);
        }
        for(int i=0;i<n;i++)
        {
            int leftSum = pre[i];
            int rightSum = pre[n]-pre[i+1];
            int res = (i*nums[i]-leftSum) + (rightSum-(n-i-1)*nums[i]);
            ans.push_back(res);
        }
        
        return ans;
    }
};