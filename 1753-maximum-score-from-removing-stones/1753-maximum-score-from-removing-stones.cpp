class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        while(!pq.empty())
        {
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int third=pq.top();
            pq.pop();
            if(second == 0 && third ==0)
                break;
            cnt++;
            first--;
            second--;
            
            pq.push(first);
            pq.push(second);
            pq.push(third);
        }
        return cnt;
    }
};