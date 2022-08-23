class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s:strs)
        {
            string tmp;
            tmp = s;
            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(s);
        }
        vector<vector<string>> ret;
        for(auto m:mp)
        {
            ret.push_back(m.second);
        }
        return ret;
    }
};