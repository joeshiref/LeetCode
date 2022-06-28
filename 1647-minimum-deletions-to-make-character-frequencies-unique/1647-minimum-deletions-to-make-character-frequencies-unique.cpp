class Solution {
public:
    int minDeletions(string s) {
        set<char>st;
        for(int i=0;i<s.size();i++)
            st.insert(s[i]);
        map<char,int>freq;
        map<int,bool>exist;
        for(int i=0;i<s.size();i++)
            freq[s[i]-'a']++;
        int cnt=0;
        for(auto ch:st)
        {
            while(freq[ch-'a']!=0 && exist[freq[ch-'a']])
            {
                cout << ch << " " << freq[ch-'a'] << endl;
                freq[ch-'a']--;
                cnt++;
                
            }
            exist[freq[ch-'a']]=true;
        }
        return cnt;
    }
};