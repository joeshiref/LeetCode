class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>pre;
        pre.push_back(0);
        for(int i=0;i<nums.size();i++)
            pre.push_back(nums[i]+pre[i]);
        for(int i=0;i<nums.size();i++)
        {
            int left = pre[i]-pre[0];
            int right = pre[nums.size()]-pre[i+1];
            if(left == right)
                return i;
        }
        return -1;
    }
};

/*
1,7,3,6,5,6
1,8,11,17,22,28
28,27,20,17,11,6


*/