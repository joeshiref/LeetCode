class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        bool vis[301][301]={};
        stack<pair<int,int> >st;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> >dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    st.push({i,j});
                    grid[i][j]='0';
                    cnt++;
                    while(!st.empty())
                    {
                        int x = st.top().first;
                        int y = st.top().second;
                        st.pop();
                        for(int i=0;i<4;i++)
                        {
                            int newx = x+dir[i][0];
                            int newy = y+dir[i][1];
                            if(newx>=0 && newx <n && newy>=0 && newy<m && grid[newx][newy]=='1')
                            {
                                st.push({newx,newy});
                                grid[newx][newy]='0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};