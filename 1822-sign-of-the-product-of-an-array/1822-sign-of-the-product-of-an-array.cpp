class Solution {
public:
    long long arraySign(vector<int>& nums) {
        int neg = 0, pos = 0, zero=0;
        for(auto & num:nums)
        {
            pos += (num>0);
            neg += (num<0);
            zero+= (num==0);
        }
        if(zero)
            return 0;
        if(neg%2==0)
            return 1;
        return -1;
    }
};