class Solution {
public:
    
    int timer;
    int vis[2001];
    vector<vector<int> >adj;
    bool dfs(int source)
    {
        if(vis[source]==1)
            return true;
        if(vis[source]==0)
        {
            vis[source]=1;
            for(int i=0;i<adj[source].size();i++)
            {
                int child = adj[source][i];
                if(dfs(child))
                    return true;
            }
        }
        vis[source]=2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        adj.resize(numCourses);
        for(auto pre:prerequisites)
        {
            int a=pre[0];
            int b=pre[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(dfs(i))
                return false;
        }
        return true;
        
        
    }
};