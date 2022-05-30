class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        for(int c=0,i=0;c<matrix[0].size();c++,i++)
        {
            for(int r=matrix.size()-1,j=0;r>=0;r--,j++)
            {
                swap(matrix[r][c],matrix[i][j]);
            }
        }
        for(int i=0,f=matrix.size()-1;i<matrix.size()/2;i++,f--)
        {
            for(int j=i,k=matrix[0].size()-1-i;j<matrix[0].size()-1-i;j++,k--)
            {
                swap(matrix[i][j],matrix[f][k]);
            }
        }
        
    }
};