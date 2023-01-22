class Solution {
public:
    bool pali(int s,int e,string &str)
    {
        while(s<e)
        {
            if(str[s++]!=str[e--])
                return false;
        }
        return true;
    }
    vector<vector<string>>ans;
    vector<string>cur;
    void solve(int idx,string & s)
    {
        if(idx>=s.length())
        {
            ans.push_back(cur);
            return;
        }
        for(int e = idx;e<s.length();e++)
        {
            if(pali(idx,e,s))
            {
                cur.push_back(s.substr(idx,e-idx+1));
                solve(e+1,s);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(0,s);
        return ans;
    }
};