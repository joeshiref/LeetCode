class Solution {
public:
    
    int n,m;
    
    int Go(int i,int j, vector<vector<int>>& grid)
    {
        while(i!=n)
        {
            //cout << i << " " << j << endl;
            if((j<0 || j>=m) || (j+1<m && grid[i][j]==1 && grid[i][j+1]==-1) || (j-1>=0 && grid[i][j]==-1 && grid[i][j-1]==1))
                return -1;
            else
            {
                if(grid[i][j]==1)
                    i++,j++;
                else
                    i++,j--;
            }
        }
        if(j<0 || j>=m)
            return -1;
        return j;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        //int res = Go(0,0,grid);
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int res = Go(0,i,grid);
            //cout << endl;
            ans.push_back(res);
        }
        return ans;
    }
};