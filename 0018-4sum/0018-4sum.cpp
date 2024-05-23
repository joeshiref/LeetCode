class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set <vector<int>> st;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                int l = j + 1;
                int r = n - 1;
                while(l<r)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum==target)
                    {
                        st.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                    }
                    else if(sum<target)
                        l++;
                    else
                        r--;
                }
            }
        }
        vector<vector<int>> res;
        for(auto ans:st)
            res.push_back(ans);

        return res;
    }
};