class Solution {
public:
    int DP[101][101];
    int solve(int m, int n) {
        if(m==1 && n==1)
            return 1;
        if(m<1 || n<1)
            return 0;
        int &ret = DP[m][n];
        if(ret!=-1)
            return ret;
        return ret=solve(m-1,n)+solve(m,n-1);
    }
    int uniquePaths(int m, int n) {
        memset(DP,-1,sizeof(DP));
        return solve(m,n);
    }
};