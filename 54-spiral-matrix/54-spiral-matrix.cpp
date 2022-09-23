class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int dir_x[]={0,1,0,-1};
	    int dir_y[]={1,0,-1,0};
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;
        int r=0,c=0,moves_n=n-1,moves_m=m-1,dir=0;
        while(cnt<n*m)
        {
            for(int i=0;i<4 && cnt<n*m;i++)
            {
                int steps_in_dir=0;
                if(i%2)
                    steps_in_dir=moves_n;
                else
                    steps_in_dir=moves_m;
                if(i==3)
                    steps_in_dir--;
                for(int j=0;j<steps_in_dir && cnt<n*m ;j++)
                {
                    ans.push_back(matrix[r][c]);
                    cnt++;
                    r+=dir_x[dir];
                    c+=dir_y[dir];
                }
                dir=(dir+1)%4;
            }
            if(cnt>=n*m)
                break;
            ans.push_back(matrix[r][c]);
            cnt++;
            r+=dir_x[dir];
            c+=dir_y[dir];
            moves_n-=2;
            moves_m-=2;
        }
        return ans;
    }
};