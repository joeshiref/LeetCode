class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        for(auto &num:nums)
        {
            if(mp[num])
                return true;
            mp[num]=true;
        }
        return false;
    }
};