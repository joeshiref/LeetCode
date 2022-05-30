class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<bitset<32> >nums;
        for(auto &v:candidates)
        {
            bitset<32>bt(v);
            nums.push_back(bt);
        }
        int mx=0;
        for(int j=0;j<32;j++)
        {
            int cnt=0;
            for(int i=0;i<candidates.size();i++)
            {
                if(nums[i][j]==1)
                    cnt++;
                
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};