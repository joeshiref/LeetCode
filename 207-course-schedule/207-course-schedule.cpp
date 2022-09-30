class Solution {
public:
    vector<vector<int> >adj;
    vector<int>vis,inRec;
    bool hasCycle;
    void dfs(int source)
    {
        if(vis[source])
            return;
        vis[source]=inRec[source] = 1;
        for(int i=0;i<adj[source].size();i++)
        {
            int child = adj[source][i];
            if(inRec[child]!=-1)
                hasCycle = 1;
            if(!vis[child])
                dfs(child);
        }
        inRec[source] = -1;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses+1);
        vis = vector<int>(numCourses,0);
        inRec = vector<int>(numCourses,-1);
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