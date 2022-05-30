class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx=-1;
        if(!needle.size())
            return 0;
        for(int i=0;i<haystack.size();i++)
        {
            bool ok=true;
            if(needle[0]==haystack[i])
            {
                for(int j=0;j<needle.size();j++)
                {
                    if(haystack[i+j]!=needle[j])
                    {
                        ok=0;
                        break;
                    }
                }
            }
            else
                ok=false;
            if(ok)
            {
                idx=i;
                break;
            }
        }
        return idx;
        
    }
};