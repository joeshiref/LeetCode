class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximumSofar = nums[0];
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>maximumSofar)
                maximumSofar=sum;
            if(sum<0)
                sum=0;
        }
        return maximumSofar;
    }
};