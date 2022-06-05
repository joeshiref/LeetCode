class Solution {
public:
    int cnt=0;
    bool visCols[9],mainDiag[20],secDiag[20];    
    void doWork(int row,int n,vector<string>&board)
    {
        if(row==n)
        {
            cnt++;
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(!visCols[col] && !mainDiag[n+row-col] && !secDiag[row+col])
            {

                board[row][col]='Q';
                visCols[col] = mainDiag[n+row-col] = secDiag[row+col] = true;
                doWork(row+1,n,board);
                visCols[col] = mainDiag[n+row-col] = secDiag[row+col] = false;
                board[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        doWork(0,n,board);
        return cnt;
    }
};