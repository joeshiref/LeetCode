class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int cnt;
    bool vis[301][301];
    int n,m;
    bool valid(int i,int j,vector<vector<char>>& grid )
    {
        return (i>=0 && i<n && j>=0 && j<m && !vis[i][j] && grid[i][j]=='1');
    }
    void dfs(int i,int j, vector<vector<char>>& grid)
    {
        vis[i][j]=true;
        for(int f=0;f<4;f++)
        {
            int x=i+dx[f];
            int y=j+dy[f];
            if(valid(x,y,grid))
                dfs(x,y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};