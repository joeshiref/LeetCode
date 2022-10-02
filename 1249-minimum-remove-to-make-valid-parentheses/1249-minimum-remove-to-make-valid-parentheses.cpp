class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>indexes;
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                indexes.push(i);
                st.push('(');
            }
            else if(s[i]==')' && st.size() && st.top()=='(')
            {
                st.pop();
                indexes.pop();
            }
            else if(s[i]==')')
            {
                indexes.push(i);
                st.push(')');
            }
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