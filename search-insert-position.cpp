class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int s=0,e=nums.size()-1;
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]<target)
                s=mid+1;
            else
                e=mid;
        }
        if(nums[e]<target)
            return nums.size();
        return e;
        
    }
};