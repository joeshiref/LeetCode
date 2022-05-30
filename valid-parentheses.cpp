class Solution {
public:
    bool isValid(string str) {
        stack<char>st;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='(')
                st.push('(');
            else if(str[i]==')')
            {
                if(st.size()&& st.top()=='(')
                    st.pop();
                else
                    st.push(')');
            }
            else if(str[i]=='{')
                st.push('{');
            else if(str[i]=='}')
            {
                if(st.size()&& st.top()=='{')
                    st.pop();
                else
                    st.push('}');
            }
            else if(str[i]=='[')
                st.push('[');
            else if(str[i]==']')
            {
                if(st.size() && st.top()=='[')
                    st.pop();
                else
                    st.push(']');
            }
        }
         if(st.size())
        return false;
    else
        return true;
    }
   
        
};