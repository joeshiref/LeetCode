class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto num:nums)
            st.insert(num);
        int mx=0;
        for(auto num:st)
        {
            if(st.find(num-1)==st.end())
            {
                int cur=num;
                int cnt=1;
                while(st.find(cur+1)!=st.end())
                {
                    cnt++;
                    cur++;
                }
                mx=max(mx,cnt);
            }
        }
        
        return mx;
    }
};