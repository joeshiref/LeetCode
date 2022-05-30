class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        for(int i=0;i<32;i++)
        {
            int bit=(n>>i)&1;
            if(bit)
                cnt++;
        }
        return cnt;
    }
};