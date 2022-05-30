class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int DP[301][301]={};
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    DP[i][j]=min({DP[i-1][j],DP[i][j-1],DP[i-1][j-1]})+1;
                    mx=max(mx,DP[i][j]);
                }
            }
        }
        return mx*mx;
    }
};