class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        else if(nums.size()==2)
        {
            if(nums[0]>nums[1])
                return 0;
            else
                return 1;
        }
        int s=0,e=nums.size()-1;
        int mid;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            
            int prev;
            int next;
            if(mid-1<0)
                prev=INT_MIN;
            else
                prev=nums[mid-1];
            if(mid+1>=nums.size())
                next=INT_MIN;
            else
                next=nums[mid+1];
            if(nums[mid]>prev && nums[mid]>next)
                return mid;
            else if(nums[mid]>prev && nums[mid]<next)
                s=mid+1;
            else if(nums[mid]<prev && nums[mid]>next)
                e=mid-1;
            else if(nums[mid]<prev && nums[mid]<next)
            {
                if(prev>next)
                    e=mid-1;
                else
                    s=mid+1;
            }
        }
        return mid;
    }
};