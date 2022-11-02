class Solution {
public:
    map<string,bool>mp;
    map<string,vector<string> >adj;
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
        queue<string>que;
        que.push(state);
        map<string,bool>vis;
        vis[state]=true;
        int sz,dep=0;
        bool cont = true;
        while(!que.empty() && cont)
        {
            sz = que.size();
            while(sz--)
            {
                string cur = que.front();
                que.pop();
                if(cur==end)
                {
                    cont = false;
                    break;
                }
                for(int i=0;i<adj[cur].size();i++)
                {
                    string child = adj[cur][i];
                    if(!vis[child])
                    {
                        que.push(child);
                        vis[child]=true;
                    }
                }
            }
            dep++;
        }
        if(!cont)
            return dep-1;
        
        return -1;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        
        for(auto genes:bank)
            mp[genes]=true;
        
        bank.push_back(start);
        
        for(int i=0;i<bank.size();i++)
        {
            for(int j=0;j<bank.size();j++)
            {
                if(validMutation(bank[i],bank[j]))
                    adj[bank[i]].push_back(bank[j]);
            }
        }
        
        return solve(start,end,bank);
    }
};