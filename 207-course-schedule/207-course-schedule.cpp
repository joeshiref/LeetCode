class Solution {
public:
    
    vector<vector<int>>adj;
    vector<int>vis,inrec;
    bool hasCycle;
    void dfs(int source)
    {
        vis[source]=inrec[source]=1;
        for(int i=0;i<adj[source].size();i++)
        {
            int child = adj[source][i];
            if(inrec[child])
                hasCycle = 1;
            else if(!vis[child])
                dfs(child);
        }
        inrec[source] = 0;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.resize(numCourses);
        for(auto vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
        }
        vis = vector<int>(numCourses,0);
        inrec = vector<int>(numCourses,0);
        
        
        for(int i=0;i<numCourses;i++)
        {
            hasCycle=0;
            dfs(i);
            if(hasCycle)
                return false;
        }
        return true;
        
    }
};