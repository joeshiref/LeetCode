class Solution {
public:
    
    int BS(int s,int e,int target,vector<int>& nums)
    {
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(target==nums[mid])
                return mid;
            else if(nums[mid]<target)
                s=mid+1;
            else
                e=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int pivotIndex=-1;
        int s=0,e=nums.size()-1;
        int current=nums[0];
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(mid<nums.size()-1 && nums[mid]>nums[mid+1])
            {
                pivotIndex=mid;
                break;
            }
            if(nums[mid]<current)
                e=mid-1;
            else if(nums[mid]>=current)
                s=mid+1;
        }
        cout << pivotIndex << endl;
        if(pivotIndex==-1)
            return BS(0,nums.size()-1,target,nums);
        else
        {
            int ans=BS(0,pivotIndex,target,nums);
            if(ans==-1)
                ans=BS(pivotIndex+1,nums.size()-1,target,nums);
            return ans;
        }
    }
};