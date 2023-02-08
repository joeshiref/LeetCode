class Solution {
public:
    
    vector<vector<int> >adj;
    vector<bool>vis;
    bool DFS(int node,int dest)
    {
        vis[node]=true;
        if(node==dest)
            return true;
        bool ret = false;
        // for(int i = 0 ;i<adj[node].size();i++)
        // int child = adj[node][i];
        for(auto & child:adj[node])
        {
            if(!vis[child])
                ret|=DFS(child,dest);
        }
        return ret;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        adj.resize(n+1);
        vis.resize(n+1,false);
        for(int i = 0 ; i < edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return DFS(source,destination);
    }
};