class Solution {
public:
    
    int expand(int left,int right,string &s)
    {
        int cnt=0;
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            cnt+=expand(i,i,s);
            cnt+=expand(i,i+1,s);
        }
        return cnt;
    }
};