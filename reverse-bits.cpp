class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>bt(n);
        uint32_t x=0;
        for(int i=0,f=31;i<32;i++,f--)
        {
            if(bt[i]==1)
                x+=(1<<f);
        }
        return x;
    }
};