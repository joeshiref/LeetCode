class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>mp;
        while(true)
        {
            if(n==1)
                return true;
            if(mp.find(n)!=mp.end())
                return false;
            mp[n]=true;
            int sum = 0;
            int temp = n;
            while(temp)
            {
                int dig = temp % 10;
                sum+=(dig*dig);
                temp/=10;
            }
            n=sum;
        }
        
        return false;
    }
};