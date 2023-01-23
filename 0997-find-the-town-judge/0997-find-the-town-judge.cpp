class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)
            return 1;
        map<int,int>mp;
        int judge = -1;
        for(auto vec:trust)
        {
            mp[vec[1]]++;
            if(mp[vec[1]]==n-1)
                judge = vec[1];
        }
        if(judge==-1)
            return judge;
        for(auto vec:trust)
        {
            if(vec[0]==judge)
                return -1;
        }
        return judge;
    }
};