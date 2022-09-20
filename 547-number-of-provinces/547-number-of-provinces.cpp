class Solution {
public:
    int n;
    vector<vector<int> >adj;
    bool vis[201];
    void dfs(int source)
    {
        vis[source]=true;
        for(int i=0;i<adj[source].size();i++)
        {
            int child = adj[source][i];
            if(!vis[child])
                dfs(child);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        adj.resize(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i);
            }
        }
        return cnt;
    }
};