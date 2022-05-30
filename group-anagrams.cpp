class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
            vector<int>cnt(26,0);
            for(int j=0;j<strs[i].size();j++)
                cnt[strs[i][j]-'a']++;
            ans[cnt].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for(auto c:ans)
        {
            vector<string>tmp;
            for(int f=0;f<c.second.size();f++)
                tmp.push_back(c.second[f]);
            res.push_back(tmp);
        }
        return res;
    }
};