class Solution {
public:
    int DP[50];
    int solve(int pos,int n)
    {
        if(pos==n)
            return 1;
        if(pos>n)
            return 0;
        if(DP[pos]!=-1)
            return DP[pos];
        return DP[pos]=solve(pos+1,n)+solve(pos+2,n);
    }
    int climbStairs(int n) {
        memset(DP,-1,sizeof(DP));
        return solve(0,n);
    }
};