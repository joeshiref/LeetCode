class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int cnt=1;
        vector<vector<int>>v;
        int s=0,e;
        for(int i=0;i<S.size()-1;i++)
        {
            if(S[i]==S[i+1])
                cnt++;
            else
            {
                e=i;
                if(cnt>=3)
                {
                    vector<int>tmp;
                    tmp.push_back(s);
                    tmp.push_back(e);
                    v.push_back(tmp);
                }
                s=e+1;
                cnt=1;
            }
        }
        if(cnt>=3)
        {
            vector<int>tmp;
            tmp.push_back(s);
            tmp.push_back(S.size()-1);
            v.push_back(tmp);
        }
        return v;
    }
};