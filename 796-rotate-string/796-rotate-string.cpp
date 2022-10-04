class Solution {
public:
    bool isSubstring(int idx,string a,string b)
    {
        for(int i=idx,j=0;j<b.size();i++,j++)
        {
            if(a[i]!=b[j])
                return false;
        }
        return true;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        string str = ""+s+s;
        for(int i=0;i<str.size();i++)
        {
            if(isSubstring(i,str,goal))
                return true;
        }
        return false;
    }
};