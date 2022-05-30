class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        map<int,bool>mp;
        for(auto s:nums)
            mp[s]=true;
        int cnt=1,mx=1,f=0,last;
        for(auto p:mp)
        {
            if(!f)
                last=p.first;
            else
            {
                if(p.first-last==1)
                {
                    cnt++;
                    mx=max(mx,cnt);
                }
                else
                    cnt=1;
                last=p.first;
            }
            f++;
                
        }
        return mx;
        
        return 0;
    }
};