class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // -4 -1 -1 0 1 2
        sort(nums.begin(),nums.end());
        vector<vector<int> >vec;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                if(nums[i]==nums[i-1])
                    continue;
            }
            int l=i+1,r=n-1;
            while(l<r)
            {
                
                if(nums[i]+nums[l]+nums[r]==0)
                {
                    vec.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    while(l<n && nums[l]==nums[l-1])
                        l++;
                }
                else if(nums[i]+nums[l]+nums[r]>0)
                {
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0)
                {
                    l++;
                }
            }
        }
        return vec;
    }
};