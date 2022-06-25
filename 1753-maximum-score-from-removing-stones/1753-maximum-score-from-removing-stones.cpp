class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a < b)
            return maximumScore(b, a, c);
        if (b < c)
            return maximumScore(a, c, b);
        if (b == 0)
            return 0;
        int cnt = max(1, b-c);
        return cnt + maximumScore(a - cnt, b - cnt, c); 
    }
};