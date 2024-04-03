class Solution {
public:
    int n,m;
    bool vis[10][10];
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    bool valid(int i,int j,vector<vector<char>>& board, char cur)
    {
        return (i>=0 && i<n && j>=0 && j<m && !vis[i][j] && board[i][j]==cur);
    }
    bool solve(int idx, int i,int j, vector<vector<char>>& board, string word)
    {
        if(idx == word.size())
            return true;
        if(!valid(i,j,board,word[idx]))
            return false;
        bool found=false;
        vis[i][j]=true;
        for(int f=0;f<4;f++)
        {
            int x=dx[f]+i;
            int y=dy[f]+j;
            found|=solve(idx+1,x,y,board,word);
            
        }
        vis[i][j]=false;
        return found;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && solve(0,i,j,board,word))
                    return true;
            }
        }
        return false;
    }
};