class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastLen = 0;
        int cnt = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(cnt)
                    lastLen = cnt;
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        if(cnt)
            lastLen = cnt;
        return lastLen;
    }
};