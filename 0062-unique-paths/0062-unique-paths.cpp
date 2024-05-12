class Solution {
public:
    int DP[101][101];
    
    int solve(int i,int j,int m,int n)
    {
        if(i==m-1 && j==n-1)
            return 1;
        if(i>m || j>n)
            return 0;
        int &ret=DP[i][j];
        if(ret!=-1)
            return ret;
        return ret=solve(i+1,j,m,n)+solve(i,j+1,m,n);
    }
    
    int uniquePaths(int m, int n) {
        
        memset(DP,-1,sizeof(DP));
        return solve(0,0,m,n);
    }
};