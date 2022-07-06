class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int, vector<int>, greater<int> > pq;
        int i,cnt,cur_day;
        i=cnt=cur_day=0;
        int n=events.size();
        while(i < n || !pq.empty())
        {
            if(pq.empty())
                cur_day=events[i][0];
            while(i<n && events[i][0] <= cur_day)
            {
                pq.push(events[i][1]);
                i++;
            }
            pq.pop();
            cnt++;
            cur_day++;
            while(!pq.empty() && pq.top() < cur_day)
                pq.pop();
        }
        return cnt;
    }
};