class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int sgn = (dividend < 0) ^ (divisor < 0);
        long long int d = abs(dividend), dv = abs(divisor), ans = 0;
        for (int i = 31; i >= 0; i--)
            if (dv << i <= d)
            {
                ans += 1LL << i;
                d -= dv << i;
            }
        if (sgn == 1) 
            ans = -ans;
        return ((ans < INT_MIN) ? INT_MIN : ((ans > INT_MAX) ? INT_MAX : ans ));
    }
};