class Solution {
    
    public double solve(double x)
    {
        double s=0,e=x;
        double eps=1e-5;
        while((e-s)>eps)
        {
            double mid=(e+s)/2.0;
            if(mid*mid>x)
                e=mid;
            else
                s=mid;
        }
        return e;
    }
    
    public int mySqrt(int x) {
        int ans=(int)solve(x);
        return ans;
    }
}