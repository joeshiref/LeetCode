class Solution {
public:
    
    unordered_map<int,vector<int> >graph;
    int DP[10][5001];
    const int mod = 1e9 + 7;
    int solve(int pos,int n)
    {
        if(n==0)
            return 1;
        if(DP[pos][n]!=-1)
            return DP[pos][n];
        int ret = 0;
        for(int i=0;i<graph[pos].size();i++)
        {
            int child = graph[pos][i];
            ret+=solve(child,n-1);
            ret%=mod;
        }
        return DP[pos][n] = ret;
    }
    
    int knightDialer(int n) {
        graph[0]={4,6};
        graph[1]={6,8};
        graph[2]={9,7};
        graph[3]={4,8};
        graph[4]={3,9,0};
        graph[5]={};
        graph[6]={1,7,0};
        graph[7]={2,6};
        graph[8]={3,1};
        graph[9]={2,4};
        memset(DP,-1,sizeof(DP));
        
        int ans = 0;
        for(int i=0;i<10;i++)
        {
            ans+=solve(i,n-1);
            ans%=mod;
        }
        return ans;
    }
};