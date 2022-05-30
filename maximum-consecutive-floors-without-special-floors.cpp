class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int mx=0;
        int cur=bottom;
        for(int i=0;i<special.size();i++)
        {
            mx=max(mx,special[i]-cur);
            cur=special[i]+1;
        }
        mx=max(mx,top-special[special.size()-1]);
        return mx;
    }
};