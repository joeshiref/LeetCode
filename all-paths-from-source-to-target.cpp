class Solution {
public:
    vector<vector<int>>ans;
    vector<int>tmp;
    int n;
    void doWork(int cur,vector<vector<int>>& graph)
    {
        if(cur==n-1)
        {
            tmp.push_back(cur);
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        tmp.push_back(cur);
        for(int i=0;i<graph[cur].size();i++)
        {
            doWork(graph[cur][i],graph);
        }
        tmp.pop_back();
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        doWork(0,graph);
        return ans;
    }
};