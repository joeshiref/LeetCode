class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())
            return false;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            bool flag = false;
            for(;j<t.size();j++)
            {
                if(s[i]==t[j])
                {
                    flag = true;
                    j++;
                    break;
                }
            }
            cout << j << " " << flag << endl;
            if(!flag)
                return false;
        }
        return true;
    }
};