class Solution {
public:
    vector<vector<string>>ans;
    bool visCols[9],mainDiag[20],secDiag[20];
    vector<string>tmp;
    void doWork(int r,int n)
    {
        if(r==n)
        {
            for(int i=0;i<tmp.size();i++)
            {
                for(int j=0;j<n;j++)
                    cout << tmp[i][j];
                cout << endl;
            }
            cout << endl;
            ans.push_back(tmp);
            return;
        }
        for(int c=0;c<n;c++)
        {
            if(!visCols[c] && !mainDiag[n+r-c] && !secDiag[r+c])
            {
                string str(n,'.');
                str[c]='Q';
                tmp.push_back(str);
                visCols[c] = mainDiag[n+r-c] = secDiag[r+c] = true;
                doWork(r+1,n);
                visCols[c] = mainDiag[n+r-c] = secDiag[r+c] = false;
                tmp.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        doWork(0,n);
        return ans;
    }
};