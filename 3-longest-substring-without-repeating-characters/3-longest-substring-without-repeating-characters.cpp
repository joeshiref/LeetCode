class Solution {
public:
    
int lengthOfLongestSubstring(string s)
{
    bool mp[200]={};
    int left=0,right=0;
    int res=0;
    while(right<s.size())
    {
        if(mp[s[right]])
        {
            res=max(res,right-left);
            while(s[left]!=s[right])
            {
                mp[s[left++]]=false;
            }
            mp[s[left++]]=false;
        }
        mp[s[right]]=true;
        right++;
    }
    res=max(res,right-left);

    
    return res;
}
};