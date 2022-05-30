class Solution {
public:
    int countTriples(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int f=1;f<=n;f++)
                {
                    if(i*i+j*j==f*f)
                        cnt++;
                }
            }
        }
        return cnt;
        
    }
};