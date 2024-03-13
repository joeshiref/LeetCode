class Solution {
public:
    int n,m;
    bool vis[201][201];
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool valid(int i,int j,vector<vector<char>>& grid)
    {
        return (i>=0 && i<n && j>=0 && j<m && vis[i][j]==false && grid[i][j]=='O');
    }
    bool onBoarder(int i,int j)
    {
        if(i==0||i==n-1||j==0||j==m-1)
            return true;
        return false;
    }
    
    void dfs(int i,int j,vector<vector<char>>& board)
    {
        vis[i][j]=true;
        for(int f=0;f<4;f++)
        {
            int x = i+dx[f];
            int y = j+dy[f];
            if(valid(x,y,board))
                dfs(x,y,board);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        memset(vis,false,sizeof(vis));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && onBoarder(i,j))
                    dfs(i,j,board);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==false)
                    board[i][j]='X';
            }
        }
    }
    
};