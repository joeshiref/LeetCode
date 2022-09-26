class Solution {
public:
    int expandOverCenter(int left,int right,string &s)
    {
        int cnt=0;
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            ans+=expandOverCenter(i,i,s);
            ans+=expandOverCenter(i,i+1,s);
        }
        return ans;
    }
};