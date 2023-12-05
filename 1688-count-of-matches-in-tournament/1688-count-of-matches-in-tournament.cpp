class Solution {
public:
    int numberOfMatches(int n) {
        int cnt=0;
        while(n>=2)
        {
            int tmp = n;
            cnt += n/2;
            n/=2;
            n+=(tmp%2);
        }
        return cnt;
    }
};