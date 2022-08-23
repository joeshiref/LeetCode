class Solution {
public:
    string sortString(string str)
    {
        int freq[26]={};
        for(auto c:str)
        {
            freq[c-'a']++;
        }
        string ret="";
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<freq[i];j++)
                ret+=(i+'a');
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s:strs)
        {
            string tmp;
            tmp = s;
            mp[sortString(tmp)].push_back(s);
        }
        vector<vector<string>> ret;
        for(auto m:mp)
        {
            ret.push_back(m.second);
        }
        return ret;
    }
};