class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0],end = intervals[0][1];
        vector<vector<int>>ret;
        for(int i=1;i<intervals.size();i++)
        {
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];
            if(end>=currentStart)
                end = max(end,currentEnd);
            else if(end<currentStart)
            {
                ret.push_back({start,end});
                start = currentStart;
                end = currentEnd;
            }
        }
        ret.push_back({start,end});
        return ret;
    }
};