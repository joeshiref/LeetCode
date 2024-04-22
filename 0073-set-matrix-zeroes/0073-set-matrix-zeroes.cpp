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
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    vec.push_back({i,j});
            }
        }
        for(int i=0;i<vec.size();i++)
        {
            pair<int,int> cell = vec[i];
            setRows(cell.first,matrix);
            setCols(cell.second,matrix);
        }
        return;
    }
};