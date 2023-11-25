class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>m1,m2;
        for(auto num:nums1)
            m1[num]=true;
        for(auto num:nums2)
            m2[num]=true;
        set<int>ans1,ans2;
        for(auto num:nums1)
        {
            if(!m2.count(num))
                ans1.insert(num);
        }
        for(auto num:nums2)
        {
            if(!m1.count(num))
                ans2.insert(num);
        }
        vector<int>res1(ans1.begin(),ans1.end()),res2(ans2.begin(),ans2.end());
        return {res1,res2};
    }
};