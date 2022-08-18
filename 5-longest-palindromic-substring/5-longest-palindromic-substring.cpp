class Solution {
public:
    
    int getMaximumPali(int left,int right,string &s)
    {
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            left--;
            right++;
        }
        return (right-left+1);
    }
    
    string longestPalindrome(string s) {
        int start=0,end=0;
        for(int i=0;i<s.size();i++)
        {
            int a=getMaximumPali(i,i,s);
            int b=getMaximumPali(i,i+1,s);
            int len=max(a,b);
            if (len > (end - start)) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        cout << end << " " << start;
        return s.substr(start+1,end-start-1);
        
    }
};