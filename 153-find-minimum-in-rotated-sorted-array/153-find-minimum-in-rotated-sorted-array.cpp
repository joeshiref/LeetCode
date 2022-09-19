class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(mid+1<nums.size() && mid-1>=0 && nums[mid]>nums[mid+1] && nums[mid-1]>nums[mid])
                break;
            if(nums[mid]>=nums[0])
                s=mid+1;
            else
                e=mid-1;
        }
        s=(s==nums.size()?0:s);        
        return nums[s];
    }
};