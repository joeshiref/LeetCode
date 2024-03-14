class Solution {
public:
    
    string run(int i,int j, string &s)
    {
        string pali="";
        while(i>=0 && j<s.size())
        {
            if(s[i]!=s[j])
                break;
            pali = s.substr(i,j-i+1);
            i--,j++;
        }
        return pali;
    }
    
    string longestPalindrome(string s) {
        
        string res="";
        int mx = 0;
        for(int i=0;i<s.size();i++)
        {
            string s1 = run(i,i,s);
            string s2 = run(i,i+1,s);
            if(s1.size()>mx)
            {
                mx = s1.size();
                res = s1;
            }
            if(s2.size()>mx)
            {
                mx = s2.size();
                res = s2;
            }
            
        }
        return res;
    }
};