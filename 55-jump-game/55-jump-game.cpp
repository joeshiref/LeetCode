class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curPos = nums.size();
        int target = 1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            int pos = i + 1;
            int afterJump = pos + nums[i];
            if(afterJump>=curPos)
                curPos=pos;
        }
        return curPos==target;
    }
};