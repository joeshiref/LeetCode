class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int firstAppear[300]={};
        memset(firstAppear,-1,sizeof(firstAppear));
        int left=0,right=0;
        int mx=0;
        while(right<s.size())
        {
            while(firstAppear[s[right]]!=-1)
            {
                firstAppear[s[left]]=-1;
                left++;
            }    
            firstAppear[s[right]]=right;
            right++;
            mx = max(mx,right-left);
        }
        
        return mx;
    }
};