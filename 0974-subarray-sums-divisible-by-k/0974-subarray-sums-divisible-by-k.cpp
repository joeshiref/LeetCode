class Solution {
public:
    int fix(int cur, int m)
    {
        return ((cur%m) + m) % m;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int prev = 0;
        for(auto & num:nums)
        {
            mp[fix(num+prev,k)]++;
            prev += num;
        }
        int ans = 0;
        for(auto m:mp)
        {
            if(m.first==0)
                ans+=(m.second*(m.second-1)/2)+m.second;
            else
                ans+=(m.second*(m.second-1)/2);
        }
        return ans;
    }
};