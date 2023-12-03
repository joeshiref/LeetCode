class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        for(int i=1;i<points.size();i++)
        {
            int a=points[i][0];
            int b=points[i][1];
            int c=points[i-1][0];
            int d=points[i-1][1];
            ans+=max(abs(a-c),abs(b-d));
        }
        return ans;
    }
};