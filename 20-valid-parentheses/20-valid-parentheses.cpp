class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(c=='{' || c=='(' || c=='[')
                st.push(c);
            else
            {
                if(st.size())
                {
                    if((c=='}' && st.top()=='{') || (c==']' && st.top()=='[') || c==')' && st.top()=='(')
                        st.pop();
                    else
                        st.push(c);
                }
                else
                    st.push(c);
            }
        }
        return !(st.size());
    }
};