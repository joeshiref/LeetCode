class Solution {
public:
    map<string,bool>mp;
    bool flag;
    bool validMutation(string a,string b)
    {
        if(a.size()!=b.size())
            return false;
        int cnt = 0;
        for(int i=0;i<a.size();i++)
            cnt+=(a[i]!=b[i]);
        return (cnt==1);
    }
    int solve(string state,string end,vector<string>& bank)
    {
        if(state==end)
        {
            flag=true;
            return 0;
        }
        int ans = 100010;
        for(int i=0;i<bank.size();i++)
        {
            if(validMutation(state,bank[i]) && !mp[bank[i]])
            {
                mp[bank[i]]=true;
                ans=min(ans,solve(bank[i],end,bank)+1);
                mp[bank[i]]=false;
            }
        }
        return ans;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int ans = solve(start,end,bank);
        return (flag==false?-1:ans);
    }
};