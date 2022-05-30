class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int>st;
        st.push(-1);
        int mx=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                int len=i-st.top();
                mx=max(mx,len);
            }
        }
        return mx;
    }
};