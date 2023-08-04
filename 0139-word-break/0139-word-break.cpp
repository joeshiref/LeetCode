class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>words;
        for(auto & word:wordDict)
            words.insert(word);
        bool vis[301]={};
        vis[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(vis[j])
                {
                    string tmp = s.substr(j,i-j);
                    if(words.find(tmp)!=words.end())
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