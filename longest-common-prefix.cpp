class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0)
            return "";
        
        int mini=INT_MAX;
        for(int i=0;i<strs.size();i++)
        {
            if(strs[i].size()<mini)
                mini=strs[i].size();
        }
        
        string ans="";
        int idx=0;
        bool flag=true;
        while(idx<mini && flag)
        {
            for(int i=0;i<strs.size()-1;i++)
            {
                if(strs[i][idx]!=strs[i+1][idx])
                    flag=false;
            }
            if(flag)
                ans+=strs[0][idx];
            idx++;
        }
        return ans;
    }
};