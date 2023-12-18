class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size())
            return 0;
        int l,r;
        l=r=0;
        int mx = INT_MIN;
        unordered_map<char,bool>mp;
        while(r<s.size())
        {
            if(mp[s[r]])
            {
                while(mp[s[r]])
                {
                    mp[s[l]]=false;
                    l++;
                }
            }
            mx = max(mx,r-l+1);
            mp[s[r]]=true;
            r++;
        }
        
        return mx;
    }
};