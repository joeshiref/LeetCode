class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int>tmp;
        vector<pair<int,int> >v;
        for(int i=0;i<intervals.size();i++)
            v.push_back({intervals[i][0],intervals[i][1]});
        sort(v.begin(),v.end());
        
        vector<vector<int> >ans;
        int a=v[0].first,b=v[0].second;
        tmp.push_back(a);
        for(int i=1;i<v.size();i++)
        {
            if(b>=v[i].first)
                b=max(b,v[i].second);
            else
            {
                tmp.push_back(b);
                ans.push_back(tmp);
                tmp.clear();
                tmp.push_back(v[i].first);
                b=v[i].second;
            }
        }
        tmp.push_back(b);
        ans.push_back(tmp);
        return ans;
    }
};