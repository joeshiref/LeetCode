class Solution {
public:
    int n;
    int DP[201][201];
    long long solve(int row,int idx,vector<vector<int>>& triangle)
    {
        if(row>=n)
            return 0;
        int &ret = DP[row][idx];
        if(ret!=-1)
            return ret;
        long long ch1=solve(row+1,idx,triangle)+triangle[row][idx];
        long long ch2=solve(row+1,idx+1,triangle)+triangle[row][idx+1];
        return ret=min(ch1,ch2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        memset(DP,-1,sizeof(DP));
        if(n==1)
            return triangle[0][0];
        return triangle[0][0]+solve(1,0,triangle);
    }
};