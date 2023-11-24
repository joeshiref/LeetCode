class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(!nums[i])
            {
                for(int s=i;s<nums.size()-1;s++)
                    swap(nums[s],nums[s+1]);
            }
        }
    }
};