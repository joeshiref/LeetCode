class Solution {
public:
    vector<vector<int> >adj;
    vector<int>vis;
    bool hasCycle;
    void dfs(int source)
    {
        if(vis[source])
            return;
        vis[source] = 2;
        for(int i=0;i<adj[source].size();i++)
        {
            int child = adj[source][i];
            if(vis[child]==2)
                hasCycle = 1;
            if(!vis[child])
                dfs(child);
        }
        vis[source]--;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses+1);
        vis = vector<int>(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++)
        {
            dfs(i);
        }
        return !hasCycle;
        
    }
};