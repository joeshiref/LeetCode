class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int rem = 0;
        int ans = -1;
        for(int i=1;i<=n;i++)
        {
            rem+=i;
            if(rem==sum)
            {
                ans = i;
            }
            sum-=i;
        }
        return ans;
    }
};