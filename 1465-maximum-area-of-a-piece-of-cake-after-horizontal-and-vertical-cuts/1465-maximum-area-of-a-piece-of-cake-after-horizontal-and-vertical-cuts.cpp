class Solution {
public:
    long long max(long long x,long long y)
    {
        if(x<y)
            return y;
        return x;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        horizontalCuts.push_back(h);
        long long maxHoriDiff=0;
        int startHori = 0;
        for(int i=0;i<horizontalCuts.size();i++)
        {
            maxHoriDiff=max(maxHoriDiff,horizontalCuts[i]-startHori);
            startHori=horizontalCuts[i];
        }
        
        sort(verticalCuts.begin(),verticalCuts.end());
        verticalCuts.push_back(w);
        long long maxVerDiff=0;
        int startVer = 0;
        for(int i=0;i<verticalCuts.size();i++)
        {
            maxVerDiff=max(maxVerDiff,verticalCuts[i]-startVer);
            startVer=verticalCuts[i];
        }
        
        int mod = 1000000007;
        
        return ((maxHoriDiff%mod)*(maxVerDiff%mod))%mod;
    }
};