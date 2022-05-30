class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        int freq1[26]={};
        int freq2[26]={};

        for(int i=0;i<s.size();i++)
            freq1[s[i]-'a']++;
        for(int i=0;i<t.size();i++)
            freq2[t[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(freq1[i]==freq2[i])
                continue;
            else
                return false;
        }
        
        return true;
    }
};