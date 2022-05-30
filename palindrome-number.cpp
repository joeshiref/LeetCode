class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        string s;
        s=to_string(x);
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        return s==tmp;
    }
};