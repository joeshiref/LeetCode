class Solution {
public:
    int minDeletions(string s) {
        int freq[26]={};
        for(auto &c:s)
            freq[c-'a']++;
        unordered_map<int,bool>mp;
        int cnt = 0;
        for(int i=0;i<26;i++)
        {
            if(!freq[i])
                continue;
            int current = freq[i];
            while(mp[current] && current)
            {
                current--;
                cnt++;
            }
            mp[current]=true;
        }
        return cnt;
    }
};