class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i=0,j=1;i<numRows;i++,j++)
        {
            ans[i]=vector<int>(j,1);
        }
        for(int i=2;i<numRows;i++)
        {
            for(int j=1;j<ans[i].size()-1;j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
        
    }
};