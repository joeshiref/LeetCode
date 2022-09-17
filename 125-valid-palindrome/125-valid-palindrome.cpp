class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto c:s)
        {
            if(isalpha(c))
                str+=tolower(c);
            else if(c>='0' && c<='9')
                str+=c;
        }
        string tmp=str;
        reverse(tmp.begin(),tmp.end());
        return tmp==str;
    }
};