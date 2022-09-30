class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            if(e>=curStart)
                e=max(curEnd,e);
            else
            {
                ans.push_back({s,e});
                s=curStart;
                e=curEnd;
                //ans.push_back({curStart,curEnd});
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};