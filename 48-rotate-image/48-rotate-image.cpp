class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int rows=matrix.size();
        int m=n;
        n/=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                swap(matrix[i][j],matrix[rows-i-1][j]);
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j>i)
                    swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};