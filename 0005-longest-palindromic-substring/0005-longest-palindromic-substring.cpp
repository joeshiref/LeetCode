class Solution {
public:
    
    int getLongestPali(int left,int right,string & str)
    {
        while(left>=0 && right<str.size() && str[left]==str[right])
        {
            left--,right++;
        }
        return (right-left)-1;
    }
    
    string longestPalindrome(string s) {
        int end = 0, start = 0;
        for(int i=0;i<s.size();i++)
        {
            int a = getLongestPali(i,i,s);
            int b = getLongestPali(i,i+1,s);
            int mx = max(a,b);
            if(mx>(end-start))
            {
                start = i - (mx - 1) / 2;
                end = i + mx / 2;
            }
        }
        return s.substr(start,end-start+1);
    }
};

