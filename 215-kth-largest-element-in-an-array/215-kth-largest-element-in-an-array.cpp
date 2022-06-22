class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto num:nums)
            pq.push(num);
        int ans=pq.top();
        while(k--)
        {
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};