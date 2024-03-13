class Solution {
public:
    int n,m;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool valid(int i,int j,vector<vector<char>>& grid)
    {
        return (i>=0 && i<n && j>=0 && j<m && grid[i][j]!='0');
    }
    void DFS(int i,int j,vector<vector<char>>& grid)
    {
        grid[i][j]='0';
        for(int f=0;f<4;f++)
        {
            int x = i+dx[f];
            int y = j+dy[f];
            if(valid(x,y,grid))                
                DFS(x,y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    DFS(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};