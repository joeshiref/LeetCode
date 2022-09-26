class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int tmp = i;
            int cnt=0;
            while(tmp)
            {
                int dig=tmp%2;
                cnt+=dig;
                tmp/=2;
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};