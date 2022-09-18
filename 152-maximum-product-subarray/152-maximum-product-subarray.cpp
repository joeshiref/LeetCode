class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=0, right=0;
        int mx = nums[0];
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            left = (left? left : 1)*nums[i];
            right = (right? right : 1)*nums[n-i-1];
            mx=max(mx,max(left,right));
        }
        return mx;
    }
};