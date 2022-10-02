class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>indexes;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                indexes.push(i);
            else if(s[i]==')' && indexes.size())
                indexes.pop();
            else if(s[i]==')')
                s[i]='#';
        }
        
        while(indexes.size())
        {
            int idx = indexes.top();
            s[idx]='#';
            indexes.pop();
        }
        string ans="";
        for(auto &c:s)
        {
            if(c=='#')
                continue;
            ans+=c;
        }
        return ans;
    }
};