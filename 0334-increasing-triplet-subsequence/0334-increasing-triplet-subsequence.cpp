class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left, mid;
        left = mid = INT_MAX;
        for(auto num:nums)
        {
            if(num>mid)
                return true;
            if(num > left && num < mid)
                mid = num;
            if(num < left)
                left = num;
        }
        return false;
    }
};