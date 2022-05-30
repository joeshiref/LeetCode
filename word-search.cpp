class Solution {
public:
    int n,m;
    bool vis[10][10];
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    bool solve(int i,int j,int idx,string goal,vector<vector<char>>& board)
    {
        if(idx==goal.size())
            return true;
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j]!=goal[idx])
            return false;
        
        bool found=false;
        vis[i][j]=true;
        for(int f=0;f<4;f++)
        {
            int x=dx[f]+i;
            int y=dy[f]+j;
            found|=solve(x,y,idx+1,goal,board);
            
        }
        vis[i][j]=false;
        return found;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
    
        n=board.size();
        m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && solve(i,j,0,word,board))
                    return true;
            }
        }
        return false;
        
        
    }
};