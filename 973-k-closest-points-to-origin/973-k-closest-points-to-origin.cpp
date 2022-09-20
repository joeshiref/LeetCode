class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue< pair<int,vector<int> > > pq;
        for(auto point:points)
        {
            int dis = point[0]*point[0] + point[1]*point[1];
            pq.push({-dis,point});
        }
        while(k--)
        {
            ans.push_back({pq.top().second[0],pq.top().second[1]});
            //cout << pq.top().second[0] << " " << pq.top().second[1] << endl;
            pq.pop();
        }
        return ans;
    }
};