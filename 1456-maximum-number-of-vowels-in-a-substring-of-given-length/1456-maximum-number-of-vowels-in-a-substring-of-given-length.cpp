class Solution {
public:
    bool checkVowel(char c)
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int cnt=0;
        for(int i=0;i<k;i++)
            cnt+=checkVowel(s[i]);
        
        int maxCnt=cnt;
        for(int i=0,j=k;j<s.size();i++,j++)
        {
            cnt-=checkVowel(s[i]);
            cnt+=checkVowel(s[j]);
            maxCnt = max(maxCnt,cnt);
        }
        return maxCnt;
    }
};