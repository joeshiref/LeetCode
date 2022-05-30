class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size();
        int m=mat[0].size();
        if(n*m!=r*c)
            return mat;
        vector<vector<int>>res(r);
        for(int i=0;i<r;i++)
        {
            res[i].resize(c);
        }
        int row=0,col=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                res[row][col++]=mat[i][j];
                if(col==c)
                {
                    col=0;
                    row++;
                }
            }
        }
        return res;
    }
};