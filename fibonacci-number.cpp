class Solution {
public:
    int fib(int N) {
        int first=0,second=1;
        if(N==0)
            return first;
        else if(N==1)
            return second;
        else
        {
            int ans;
            for(int i=2;i<=N;i++)
            {
                ans=first+second;
                first=second;
                second=ans;
            }
            return ans;
        }
    }
};