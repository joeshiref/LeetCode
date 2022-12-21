class Solution {
public:
    vector<vector<int> >adj;
    
    bool BFS(int source,vector<int>&color)
    {
        queue<int>que;
        que.push(source);
        color[source]=0;
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            for(int i=0;i<adj[cur].size();i++)
            {
                int next = adj[cur][i];
                if(color[next] == color[cur])
                    return false;
                if(color[next]==-1)
                {
                    color[next]=1-color[cur];
                    que.push(next);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        adj.resize(n+1);
        vector<int>vis(n+1,-1);
        for(auto vec:dislikes)
        {
            int a = vec[0];
            int b = vec[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==-1)
            {
                if(BFS(i,vis)==false)
                    return false;
            }
        }
        return true;
    }
};