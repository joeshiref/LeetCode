class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue< pair<int,int> >pq;
        for(auto num:nums)
            mp[num]++;
        for(auto m:mp)
            pq.push({m.second,m.first});
        
        vector<int>ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
            
    }
};