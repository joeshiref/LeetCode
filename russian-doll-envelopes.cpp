class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>v;
        for(int i=0;i<envelopes.size();i++)
        {
            auto it=lower_bound(v.begin(),v.end(),envelopes[i][1]);
            if(it==v.end())
                v.push_back(envelopes[i][1]);
            else
                *it=envelopes[i][1];
        }
        return v.size();
    }
};