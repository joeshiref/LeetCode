class Solution {
public:
    
    long long funCalc(long long x)
    {
        return (x*(x+1))/2;
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int a=0,b=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>right)
            {
                ans+=funCalc(a)-funCalc(b);
                a=0;
                b=0;
            }
            else if(nums[i]<left)
            {
                b++;
                a++;
            }
            else
            {
                ans-=funCalc(b);
                b=0;
                a++;
            }
        }
        ans+=funCalc(a)-funCalc(b);
        return ans;
    }
};