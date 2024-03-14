class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int appear[300];
        memset(appear,-1,sizeof(appear));
        int l = 0;
        int mx = 0;
        for(int r=0;r<s.size();r++)
        {
            if(appear[s[r]]>=l)
                l = appear[s[r]] + 1;
            appear[s[r]] = r;
            mx = max(mx, r-l+1);
        }
        return mx;
    }
};