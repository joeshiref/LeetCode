class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            int s=i;
            int cnt=0;
            while(s)
            {
                cnt+=(s%2==1);
                s=s>>1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};