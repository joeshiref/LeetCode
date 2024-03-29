class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            int current = nums[mid];
            if((target < nums[0] && current < nums[0]) || target >= nums[0] && current >= nums[0])
                current = nums[mid];
            else
            {
                if(target < nums[0])
                    current = INT_MIN;
                else
                    current = INT_MAX;
            }
            if(target == current)
                return mid;
            else if(target > current)
                s = mid+1;
            else
                e = mid-1;
        }
        return -1;
    }
};