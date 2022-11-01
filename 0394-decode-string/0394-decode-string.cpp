class Solution {
public:
    
    string solve(string s,int & i)
    {
        string res = "";
        while(i<s.size() && s[i] != ']')
        {
            if(!isdigit(s[i]))
                res+=s[i++];
            else
            {
                int num=0;
                while(i<s.size() && isdigit(s[i]))
                    num = num*10 + s[i++]-'0';
                i++;
                string tmp = solve(s,i);
                i++;
                while(num--)
                    res+=tmp;
            }
        }
        return res;
    }
    
    string decodeString(string s) {
        int i=0;
        return solve(s,i);
    }
};