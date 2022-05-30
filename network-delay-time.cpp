class Solution {
public:
    const static int SIZE=200;
    int sz;
    vector<vector<pair<long long,long long> > >adj;
    long long dist[SIZE];
    long long Dijkstra(int source)
    {
        priority_queue<pair<long long,long long> >pq;
        pq.push({0,source});
        dist[source]=0;
        long long mx=-1;
        while(!pq.empty())
        {
            pair<long long,long long>cur=pq.top();
            long long c=-cur.first;
            long long a=cur.second;
            pq.pop();
            for(int i=0;i<adj[a].size();i++)
            {
                pair<long long,long long>nxt=adj[a][i];
                long long dest=nxt.second;
                long long cost=nxt.first;
                if(dist[a]+cost<dist[dest])
                {
                    pq.push({-cost,dest});
                    dist[dest]=dist[a]+cost;
                }
            }
        }
        for(int i=1;i<=sz;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            mx=max(mx,dist[i]);
        }
        return mx;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        sz=n;
        adj.resize(n+1);
        for(int i=0;i<SIZE;i++)
            dist[i]=INT_MAX;
        for(auto v:times)
        {
            adj[v[0]].push_back({v[2],v[1]});
        }
        
        return Dijkstra(k);
    }
};