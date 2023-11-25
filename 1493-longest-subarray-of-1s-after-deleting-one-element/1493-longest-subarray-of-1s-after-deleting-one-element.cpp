class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l,r;
        l=r=0;
        int ans = 0,lastZero=-1;
        while(r<nums.size())
        {
            
            if(!nums[r] && lastZero == -1)
            {
                lastZero = r;
            }
            else if(!nums[r])
            {
                l=lastZero+1;
                lastZero = r;
            }
            ans = max(ans,r-l);
            r++;
        }
        return ans;
    }
};