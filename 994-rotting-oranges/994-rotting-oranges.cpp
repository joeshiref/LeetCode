class Solution {
public:
    
    vector<vector<int> >dir ={{1,0},{-1,0},{0,1},{0,-1}};
    int n,m,dep=-1;
    queue<pair<int,int> >q;
    void bfs(vector<vector<int>>& grid)
    {
        int sz;
        while(!q.empty())
        {
            sz=q.size();
            while(sz--)
            {
                pair<int,int> cur = q.front();
                q.pop();
                for(int i=0;i<dir.size();i++)
                {
                    int newx = cur.first + dir[i][0];
                    int newy = cur.second + dir[i][1];
                    if(newx >=0 && newx < n && newy >=0 && newy < m && grid[newx][newy]==1)
                    {
                        q.push({newx,newy});
                        grid[newx][newy]=0;
                    }
                }
            }
            dep++;
        }
        
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    grid[i][j]=0;
                }
            }
        }
        bfs(grid);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    return -1;
            }
        }
        cout << dep << endl;
        return max(0,dep);
    }
};