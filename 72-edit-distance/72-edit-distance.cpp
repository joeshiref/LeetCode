class Solution {
public:
    int DP[501][501];
    int solve(int i, int j, string word1, string word2)
    {
        if(i==0)
            return j;
        if(j==0)
            return i;
        if(DP[i][j]!=-1)
            return DP[i][j];
        if(word1[i-1]==word2[j-1])
            return DP[i][j]=solve(i-1,j-1,word1,word2);
        int ch1 = solve(i-1,j,word1,word2);
        int ch2 = solve(i,j-1,word1,word2);
        int ch3 = solve(i-1,j-1,word1,word2);
        return DP[i][j]=min(ch1,min(ch2,ch3))+1;
    }
    int minDistance(string word1, string word2) {
        memset(DP,-1,sizeof(DP));
        return solve(word1.size(),word2.size(),word1,word2);
    }
};