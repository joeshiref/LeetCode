class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>bt(n);
        bitset<32>ans;
        for(int i=0,j=31;i<32;i++,j--)
            ans[j]=bt[i];
        int mybit_int;
        mybit_int = (int)(ans.to_ulong());
        
        return mybit_int;
    }
};