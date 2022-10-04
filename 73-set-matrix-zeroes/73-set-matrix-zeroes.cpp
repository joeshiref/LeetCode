class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row[202]={};
        int col[202]={};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[j]=1;
                    col[i]=1;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(row[i]==1)
            {
                for(int f=0;f<n;f++)
                    matrix[f][i]=0;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(col[i]==1)
            {
                for(int f=0;f<m;f++)
                    matrix[i][f]=0;
            }
        }
    }
};