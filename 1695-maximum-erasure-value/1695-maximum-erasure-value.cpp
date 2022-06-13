class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int>pre(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i-1];
        }
        int left=0,right=0;
        int mx=0,sum=0;
        vector<int>mp(10001,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]!=-1)
            {
                sum=pre[right]-pre[left];
                mx=max(mx,sum);
                while(left<=mp[nums[i]])
                {
                    mp[nums[left]]=-1;
                    left++;
                }
            }
            mp[nums[right]]=i;
            right++;
        }
        sum=pre[right]-pre[left];
        mx=max(mx,sum);
        return mx;
    }
};