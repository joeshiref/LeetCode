class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>mp;
        int cnt=0,mxlength=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            cnt = cnt + (nums[i] == 1 ? 1 : -1);
            if(mp.find(cnt)!=mp.end())
                mxlength = max(mxlength,i-mp[cnt]);
            else
                mp[cnt]=i;
        }
        return mxlength;
    }
};