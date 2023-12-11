class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        int qu = arr.size()/4;
        for(auto num:arr)
        {
            mp[num]++;
            if(mp[num]>qu)
                return num;
        }
        return 0;
        
    }
};