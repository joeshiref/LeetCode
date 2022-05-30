class Solution {
public:
    vector<vector<int> >edges,adj;
    int dfn[100001],lowLink[100001];
    stack<int>stk;
    int dfnNumber=0;
    void solve(int node,int par)
    {
        dfn[node]=lowLink[node]=dfnNumber++;
        for(int i=0;i<adj[node].size();i++)
        {
            int ch=adj[node][i];
            if(dfn[ch]==-1)
            {
                //cout << node << " " << ch << " ";
                solve(ch,node);
                lowLink[node]=min(lowLink[node],lowLink[ch]);
                //cout << lowLink[ch] << " " << dfn[ch] << endl;
                if(lowLink[ch]==dfn[ch])
                {
                    vector<int>tmp;
                    tmp.push_back(node);
                    tmp.push_back(ch);
                    edges.push_back(tmp);
                }
            }
            else if(par!=ch)
                lowLink[node]=min(lowLink[node],lowLink[ch]);
        }

    }

    vector<vector<int> > criticalConnections(int n, vector<vector<int> >& connections) {
        adj.resize(n+1);
        for(int i=0;i<connections.size();i++)
        {
            vector<int>v=connections[i];
            int a=v[0],b=v[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        memset(dfn,-1,sizeof(dfn));
        solve(0,-1);
        return edges;
    }
};