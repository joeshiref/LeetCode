class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26]={};
        int freq2[26]={};
        for(auto &c:s)
            freq[c-'a']++;
        for(auto &c:t)
            freq2[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=freq2[i])
                return false;
        }
        return true;
    }
};