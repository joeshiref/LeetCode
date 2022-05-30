class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<vector<int> >a,b;
        a.resize(256);
        b.resize(256);
        for(int i=0;i<s.size();i++)
        {
            a[s[i]].push_back(i);
        }
        for(int i=0;i<t.size();i++)
        {
            b[t[i]].push_back(i);
        }
        for(int i=0;i<s.size();i++)
        {
            char first=s[i],second=t[i];
            if(a[first].size()!=b[second].size())
                return false;
            else
            {
                for(int j=0;j<a[first].size();j++)
                {
                    if(a[first][j]!=b[second][j])
                        return false;
                }
            }
        }
        return true;
    }
};