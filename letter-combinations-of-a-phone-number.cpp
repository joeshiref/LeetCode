class Solution {
public:
    
    map<int,vector<char>>mp;
    vector<string>ans;
    void solve(int idx,string tmp, string digits)
    {
        if(idx>=digits.size())
        {
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<mp[digits[idx]-'0'].size(); i++)
        {
            solve(idx+1,tmp+mp[digits[idx]-'0'][i],digits);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if(!digits.size())
            return ans;
        mp[2]= {'a','b','c'};
        mp[3]= {'d','e','f'};
        mp[4]= {'g','h','i'};
        mp[5]= {'j','k','l'};
        mp[6]= {'m','n','o'};
        mp[7]= {'p','q','r','s'};
        mp[8]= {'t','u','v'};
        mp[9]= {'w','x','y','z'};

        solve(0,"",digits);
        sort(ans.begin(),ans.end());
        return ans;
    }
};