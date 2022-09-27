class Solution {
public:
    unordered_map<int,vector<char> >mp;
    vector<string> ans;
    void buildMap()
    {
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};
    }
    
    void solve(int idx,string str,string digs)
    {
        if(idx>=digs.size())
        {
            ans.push_back(str);
            return;
        }
        vector<char> cur = mp[digs[idx]-'0'];
        for(int i=0;i<cur.size();i++)
            solve(idx+1,str+cur[i],digs);
    }
    
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return {};
        buildMap();
        solve(0,"",digits);
        return ans;
    }
};