class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len = min(word1.size(),word2.size());
        string ans = "";
        for(int i=0;i<len;i++)
        {
            ans+=word1[i];
            ans+=word2[i];
        }
        for(int i=len;i<word1.size();i++)
                ans+=word1[i];
        for(int i=len;i<word2.size();i++)
                ans+=word2[i];
        return ans;
    }
};