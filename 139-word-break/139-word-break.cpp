class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dic;
        for(auto str:wordDict)
            dic.insert(str);
        bool vis[301]={};
        vis[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(vis[j])
                {
                    string str = s.substr(j,i-j);
                    cout << str << endl;
                    if(dic.find(str)!=dic.end())
                    {
                        vis[i]=true;
                        break;
                    }
                }
            }
        }
        return vis[s.size()];
    }
};