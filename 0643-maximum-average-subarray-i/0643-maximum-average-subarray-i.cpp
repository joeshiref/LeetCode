class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg;
        double sum = 0;
        for(int i=0;i<k;i++)
            sum += nums[i];
        maxAvg = sum/k;
        for(int i=0,j=k;j<nums.size();i++,j++)
        {
            sum-=nums[i];
            sum+=nums[j];
            maxAvg = max(maxAvg,sum/k);
        }
        return maxAvg;
    }
};