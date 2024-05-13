class Solution {
public:
    int n,m;
    int calculateRow(vector<int>row)
    {
        int s = 1,score=0;
        for(int i=row.size()-1;i>=0;i--)
        {
            if(row[i])
                score+=s;
            s *= 2;
        }
        return score;
    }
    
    int calculateMatrixScore(vector<vector<int>>& grid)
    {
        int score = 0;
        for(int i=0;i<n;i++)
        {
            score+=calculateRow(grid[i]);
        }
        return score;
    }
    
    void toggleRow(vector<vector<int>>& grid,int rowIdx)
    {
        for(int i=0;i<m;i++)
        {
            grid[rowIdx][i]=!grid[rowIdx][i];
        }
    }
    
    void toggleCol(vector<vector<int>>& grid,int colIdx)
    {
        for(int i=0;i<n;i++)
        {
            grid[i][colIdx]=!grid[i][colIdx];
        }
    }
    
    int toggleOrNot(vector<vector<int>>& grid,int colIdx)
    {
        int zeros = 0,ones = 0;
        for(int i=0;i<n;i++)
        {
            int num = grid[i][colIdx];
            if(!num)
                zeros++;
            else
                ones++;
        }
        
        return (zeros>ones);
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][0]==0)
                {
                    // toggle
                    toggleRow(grid,i);
                    
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            if(toggleOrNot(grid,i))
            {
                toggleCol(grid,i);
            }
        }
        
        
        return calculateMatrixScore(grid);
    }
};