class Solution {
    int [] DP;
    
    public int solve(int n)
    {
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        if(DP[n]!=-1)
            return DP[n];
        return DP[n]=solve(n-1)+solve(n-2);
        
    }
    
    public int climbStairs(int n) {
        DP=new int[100];
        Arrays.fill(DP, -1);
        return solve(n);
        
    }
}