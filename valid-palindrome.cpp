class Solution {
public:
    bool isPalindrome(string s) {
        
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
                str+=tolower(s[i]);
            else if (s[i]>='0' && s[i]<='9')
                str+=s[i];
        }
        string tmp=str;
        reverse(tmp.begin(),tmp.end());
        return tmp==str;
    }
};