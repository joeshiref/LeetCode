class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0,j=nums.size()-1;i<j &&nums[i]<k;)
        {
            if(nums[i]+nums[j]<k)
                i++;
            else if(nums[i]+nums[j]>k)
                j--;
            else
            {
                cnt++;
                i++;
                j--;
            }
        }
        return cnt;
    }
};

/*
    [3,1,3,4,3], k = 6
    [1,3,3,3,4], k = 6
    
*/