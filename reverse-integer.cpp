class Solution {
public:
    int reverse(int x) {
        vector<int>v;
        while(x)
        {
            int digit=x%10;
            v.push_back(digit);
            x/=10;
        }
        int len=v.size();
        long long s=pow(10,len-1);
        long long res=0,i=0;
        while(len--)
        {
            res+=(v[i]*s);
            s/=10;
            i++;
        }
        if(res>INT_MAX || res<INT_MIN)
            return 0;
        return res;
    }
};