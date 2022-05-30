class Solution {
public:
    vector<int>ans;
    bool vis[2000];
    int indegree[2001];
    vector<vector<int> >adj;
    int n;
    bool cycle;
    void solve()
    {
        cycle=false;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            if(vis[cur])
                continue;
            ans.push_back(cur);
            vis[cur]=true;
            for(int i=0;i<adj[cur].size();i++)
            {
                int child=adj[cur][i];
                if(!(--indegree[child]))
                    q.push(child);
            }
        }
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n=numCourses;
        adj.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        solve();
        if(ans.size()==n)
            return ans;
        vector<int>vv;
        return vv;

    }
};