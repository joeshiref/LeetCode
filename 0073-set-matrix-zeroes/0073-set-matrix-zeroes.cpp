class Solution {
public:
    int n,m;
    void setRows(int i, vector<vector<int>>& matrix)
    {
        for(int f=0;f<m;f++)
            matrix[i][f]=0;
    }
    void setCols(int j, vector<vector<int>>& matrix)
    {
        for(int f=0;f<n;f++)
            matrix[f][j]=0;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<pair<int,int> >vec;
        bool fr = 0, fc = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(matrix[i][j]==0)
                {
                    if(i==0)fr=1;
                    if(j==0)fc=1;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[0][j]==0)
                {
                    for(int f=0;f<n;f++)
                        matrix[f][j]=0;
                }
                else if(matrix[i][0]==0)
                {
                    for(int f=0;f<m;f++)
                        matrix[i][f]=0;
                }
            }
        }
        if(fr)
        {
            for(int f=0;f<m;f++)
                matrix[0][f]=0;
        }
        if(fc)
        {
            for(int f=0;f<n;f++)
                matrix[f][0]=0;
        }
        return;
    }
};