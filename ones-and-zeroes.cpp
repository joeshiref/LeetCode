class Solution {
public:
    vector<pair<int,int> >values;
    int DP[101][101][601];
    int doWork(int rem1,int rem2,int idx)
    {
        if(idx>=values.size() || rem1<0 || rem2<0)
            return 0;
        int &ret=DP[rem1][rem2][idx];
        if(ret!=-1)
            return ret;
        int c1=doWork(rem1,rem2,idx+1);
        int c2=0;
        if(rem1 >= values[idx].first && rem2 >= values[idx].second)
            c2=doWork(rem1-values[idx].first,rem2-values[idx].second,idx+1)+1;
        return ret=max(c1,c2);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(DP,-1,sizeof(DP));
        for(int i=0;i<strs.size();i++)
        {
            int zeros=0,ones=0;
            for(int j=0;j<strs[i].size();j++)
            {
                ones+=(strs[i][j]=='1');
                zeros+=(strs[i][j]=='0');
            }
            values.push_back({zeros,ones});
        }
        return doWork(m,n,0);
        
    }
};