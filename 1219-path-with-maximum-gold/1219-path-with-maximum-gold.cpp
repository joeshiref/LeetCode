class Solution {
public:
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int n,m;
    bool valid(vector<vector<int>>& grid,int i,int j)
    {
        return (i>=0 && i<n && j>=0 && j<m && grid[i][j]!=0);
    }
    int solve(int i, int j, vector<vector<int>>& grid)
    {
        if(!valid(grid,i,j))
            return 0;
        int mxGold = 0;
        int num = grid[i][j];
        grid[i][j]=0;
        for(int f=0;f<4;f++)
        {
            int nx = i+dx[f];
            int ny = j+dy[f];
            mxGold = max(mxGold,solve(nx,ny,grid));
        }
        grid[i][j]=num;
        return mxGold + num;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    mx=max(mx,solve(i,j,grid));
                }
            }
        }
        return mx;
    }
};