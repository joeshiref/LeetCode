class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                if(i-2>=0 && nums[i]>=nums[i-2])
                    nums[i-1]=nums[i];
                else if(i-2>=0 && nums[i]<nums[i-2])
                    nums[i]=nums[i-1];
                cnt++;
            }
        }
        return cnt<=1;
    }
};