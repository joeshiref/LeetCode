class Solution {
public:
    int calcDistance(vector<int>&a)
    {
        return (a[0]*a[0] + a[1]*a[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int,vector<int> > >pq;
        for(auto v:points)
        {
            int dis=calcDistance(v);
            pq.push({-dis,v});
        }
        vector<vector<int>>v;
        while(k--)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};