class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cntZeros = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(!nums[i])
                cntZeros++;
            else
            {
                int tmp = nums[i];
                nums[i] = 0;
                nums[i-cntZeros] = tmp;
            }
        }
    }
};