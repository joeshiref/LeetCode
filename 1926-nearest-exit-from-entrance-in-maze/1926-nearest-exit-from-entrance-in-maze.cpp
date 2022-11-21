class Solution {
public:
    
    int cost[101][101];
    vector<vector<int> >dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int BFS(vector<vector<char>>& maze, vector<int>& entrance)
    {
        queue<vector<int> >que;
        que.push(entrance);
        int cur_x = entrance[0];
        int cur_y = entrance[1];
        cost[cur_x][cur_y] = -1;
        int dep = 1;
        int sz;
        int mn = INT_MAX;
        while(!que.empty())
        {
            
            sz = que.size();
            while(sz--)
            {
                cur_x = que.front()[0];
                cur_y = que.front()[1];
                que.pop();
                for(int i=0;i<dir.size();i++)
                {
                    int newx = cur_x + dir[i][0];
                    int newy = cur_y + dir[i][1];
                    if(newx >= 0 && newx < maze.size() && newy >=0 && newy < maze[0].size() && maze[newx][newy]=='.' && cost[newx][newy]==0)
                    {
                        que.push({newx,newy});
                        cost[newx][newy] = dep;
                        if(newx==0 || newx == maze.size()-1 || newy == 0 || newy == maze[0].size()-1)
                            mn=min(mn,dep);
                    }
                }
            }
            dep++;
        }
        
        return mn==INT_MAX?-1:mn;
        
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        return BFS(maze,entrance);
    }
};