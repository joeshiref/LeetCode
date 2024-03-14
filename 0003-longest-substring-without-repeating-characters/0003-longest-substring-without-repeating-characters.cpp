class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int appear[300];
        memset(appear,-1,sizeof(appear));
        int l = 0, r = 0;
        int mx = 0;
        while(r<s.size())
        {
            if(appear[s[r]]!=-1)
            {
                while(l<=appear[s[r]])
                {
                    appear[s[l]] = -1;
                    l++;
                }
            }
            appear[s[r]] = r;
            r++;
            mx=max(mx,r-l);
        }
        return mx;
    }
};