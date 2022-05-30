class Solution {
public:
    bool pali(string s, int i,int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
                i++,j--;
            else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0,end=s.size()-1;
        while(start<end)
        {
            if(s[start]==s[end])
                start++,end--;
            else
                return pali(s,start+1,end)|pali(s,start,end-1);
        }
        return true;
    }
};