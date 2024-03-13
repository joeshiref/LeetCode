class Solution {
public:
    int n,m;
    int DP[201][201];
    int solve(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=n || j>=m)
            return 1000000;
        if(i==n-1 && j==m-1)
            return grid[i][j];
        int & ret = DP[i][j];
        if(~ret)
            return ret;
        int ch1 = grid[i][j] + solve(i+1,j,grid);
        int ch2 = grid[i][j] + solve(i,j+1,grid);
        return ret = min(ch1,ch2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(DP,-1,sizeof(DP));
        return solve(0,0,grid);
    }
};