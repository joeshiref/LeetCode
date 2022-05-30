class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans=-1;
        for(int i=0;i<nums.size()-2;i++)
        {
            int start=i+1,end=nums.size()-1;
            while(start<end)
            {
                int res=nums[i]+nums[start]+nums[end];
                
                if(abs(target-res)<diff)
                {
                    ans=res;
                    diff=abs(target-res);
                }
                if(res<target)
                    start++;
                else
                    end--;
                
            }
        }
        return ans;
        
    }
};