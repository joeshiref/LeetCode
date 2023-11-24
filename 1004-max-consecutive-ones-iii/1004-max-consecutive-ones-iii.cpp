class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int maxSofar = 0;
        int rem = k;
        int l,r;
        l = r = 0;
        while(r<nums.size())
        {
            cout << l << " " << r << endl;
            if(nums[r]==0 && rem)
                rem--;
            else if(nums[r]==0 && !rem)
            {
                while(nums[l]==1 && l<nums.size())
                    l++;
                l++;
            }
            r++;
            maxSofar = max(maxSofar,r-l);
        }
        return maxSofar;
    }
};