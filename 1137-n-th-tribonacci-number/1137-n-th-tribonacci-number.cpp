class Solution {
public:
    int DP[50]={};
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n<=2)
            return 1;
        if(DP[n])
            return DP[n];
        return DP[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};