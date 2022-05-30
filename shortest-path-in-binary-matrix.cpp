class Solution {
public:
    bool vis[101][101];
    int n;
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    bool valid(int i,int j,vector<vector<int>>& grid)
    {
        return (i<n && i>=0 && j<n && j>=0 && !vis[i][j] && grid[i][j]==0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int len=0,sz=1;
        queue<pair<int,int>>q;
        n=grid.size();
        if(!valid(0,0,grid))
            return -1;
        q.push({0,0});
        
        vis[0][0]=true;
        bool flag=false;
        for(;!q.empty()&&!flag;sz=q.size(),++len)
        {
            while(sz--)
            {
                pair<int,int>cur=q.front();
                q.pop();
                int cur_x=cur.first;
                int cur_y=cur.second;
                if(cur_x==n-1 && cur_y==n-1)
                {
                    flag=true;
                    break;
                }
                for(int i=0;i<dir.size();i++)
                {
                    int x=dir[i].first;
                    int y=dir[i].second;
                    if(valid(cur_x + x,cur_y + y, grid))
                    {
                        q.push({cur_x + x,cur_y + y});
                        vis[cur_x + x][cur_y + y]=true;
                    }
                }
                
            }
        }
        return flag?len:-1;
    }
};