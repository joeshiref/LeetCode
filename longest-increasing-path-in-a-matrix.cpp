class Solution {
public:
    int n,m;
    int DP[201][201];
    vector<pair<int,int> > dir={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
    bool valid(int i,int j)
    {
        return (i<n && i>=0 && j<m && j>=0);
    }
    
    int solve(int i,int j, vector<vector<int>>& matrix)
    {
        if(!valid(i,j))
            return 0;
        if(DP[i][j]!=-1)
            return DP[i][j];
        
        int a=0,b=0,c=0,d=0;
        if(valid(i+1,j) && matrix[i+1][j]>matrix[i][j])
            a=solve(i+1,j,matrix);
        if(valid(i-1,j) && matrix[i-1][j]>matrix[i][j])
            b=solve(i-1,j,matrix);
        if(valid(i,j+1) && matrix[i][j+1]>matrix[i][j])
            c=solve(i,j+1,matrix);
        if(valid(i,j-1) && matrix[i][j-1]>matrix[i][j])
            d=solve(i,j-1,matrix);
        return DP[i][j]=max(a,max(b,max(c,d)))+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(DP,-1,sizeof(DP));
        n=matrix.size();
        m=matrix[0].size();
        int mx=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(DP[i][j]==-1)
                {
                    mx=max(mx,solve(i,j,matrix));
                }
            }
        }
        return mx;
    }
};