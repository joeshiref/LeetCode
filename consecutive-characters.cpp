class Solution {
public:
    int maxPower(string s) {
        int cnt=1;
        int mx=1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
                cnt++;
            else
                cnt=1;
            mx=max(mx,cnt);
        }
        return mx;
    }
};