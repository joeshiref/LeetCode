class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int tmp = i;
            int cnt=__builtin_popcount(tmp);
            ans.push_back(cnt);
        }
        return ans;
        
    }
};