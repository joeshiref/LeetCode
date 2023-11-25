class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int >mp;
        for(auto vec:grid)
            mp[vec]++;;
        
        int cnt=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            vector<int>tmp;
            for(int j=0;j<n;j++)
            {
                tmp.push_back(grid[j][i]);
            }
            cnt+=mp[tmp];
        }
        return cnt;
    }
};