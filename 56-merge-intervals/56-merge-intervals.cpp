class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            int s,e;
            s=intervals[i][0];
            e=intervals[i][1];
            if(end>=s)
                end = max(end,e);
            else
            {
                ans.push_back({start,end});
                start = s;
                end = e;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};