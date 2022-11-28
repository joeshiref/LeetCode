class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>>ans;
        vector<int>tmp;
        map<int,int>loses;
        map<int,bool>vis;
        for(auto vec:matches)
            loses[vec[1]]++;
        
        for(auto vec:matches)
        {
            if(!loses[vec[0]] && vis[vec[0]]==false)
            {
                tmp.push_back(vec[0]);
                vis[vec[0]]=true;
            }
        }
        sort(tmp.begin(),tmp.end());
        ans.push_back(tmp);
        tmp.clear();
        for(auto ele:loses)
        {
            if(ele.second==1)
                tmp.push_back(ele.first);
        }
        sort(tmp.begin(),tmp.end());
        ans.push_back(tmp);
        return ans;
    }
};