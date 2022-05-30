class Solution {
public:
    
    long long fast_power_mod(long long x, long long y,long long m)
    {
        if (y == 0)
            return 1;
        long long temp = fast_power_mod(x, y / 2, m) ;
        temp = (temp*temp)% m;
        if (y % 2 != 0)
            temp = (temp*x)% m;
        return temp;

    }
    int countGoodNumbers(long long n) {
        
        long long evens=(n/2)+(n%2==1);
        long long odds=n/2;
        long long res1=fast_power_mod(5,evens,1000000007);
        res1%=1000000007;
        
        long long res2=1;
        if(odds)
            res2=fast_power_mod(4,odds,1000000007);
        res2%=1000000007;
        
        long long ans=(res1*res2)%1000000007;
        return ans;
        
    }
};