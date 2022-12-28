class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int sum = 0, remove = 0;
        for(auto &pile:piles)
        {
            pq.push(pile);
            sum+=pile;
        }
        while(k--)
        {
            int cur = pq.top();
            if(cur == 1)
                break;
            remove += (cur/2);
            pq.pop();
            pq.push((cur+1)/2);
        }
        
        return sum-remove;
    }
};