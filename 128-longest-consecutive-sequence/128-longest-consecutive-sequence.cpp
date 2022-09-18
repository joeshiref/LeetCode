class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto num:nums){
            mp[num]=1;
        }
        int len,mx=0;
        
        for(auto num:nums)
        {
            
            if(mp[num-1]==0)
            {
                int cur=num;
                len = 1;
                while(mp[cur+1])
                {
                    cur++;
                    len++;
                }
                mx=max(mx,len);
            }
        }
        
        return mx;
    }
};