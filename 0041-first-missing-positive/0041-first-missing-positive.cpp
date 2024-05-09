class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int mx=1e5;
        for(auto num:nums)
            mp[num]=true;
        int i=1;
        while(i<=mx){
            if(!mp[i])
                return i;
            i++;
        }
        return i;
    }
};