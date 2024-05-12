class Solution {
public:
    
    int findMaxInMatrix(vector<vector<int>>& grid,int r,int c)
    {
        int mx=grid[r][c];
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                mx=max(mx,grid[i][j]);
            }
        }
        return mx;
    }
    
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<n-2;i++)
        {
            vector<int>tmp;
            for(int j=0;j<m-2;j++)
            {
                int res=findMaxInMatrix(grid,i,j);
                tmp.push_back(res);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};