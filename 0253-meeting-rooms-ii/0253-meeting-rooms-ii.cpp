class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int prefix[1000010]={};
        for(auto vec:intervals)
        {
            int a=vec[0],b=vec[1];
            prefix[a+1]++;
            prefix[b+1]--;
        }
        int mx = prefix[0];
        for(int i=1;i<1000010;i++)
        {
            prefix[i]+=prefix[i-1];
            mx = max(mx,prefix[i]);
        }
        return mx;
    }
};