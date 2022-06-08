class Solution {
public:
    int removePalindromeSub(string s) {
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        if(s==tmp)
            return 1;
        return 2;
    }
};