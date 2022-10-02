class Solution {
public:
    bool pali(int i,int j,string &s)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int i=0,j=s.size()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
                return pali(i,j-1,s)|pali(i+1,j,s);
        }
        return true;
    }
};