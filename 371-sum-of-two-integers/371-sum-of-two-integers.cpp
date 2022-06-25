class Solution {
public:
    int Add(int x, int y)
    {
        while (y != 0)
        {
            unsigned carry = x & y;
            x = x ^ y;
            y = carry << 1;
        }
        return x;
    }
    int getSum(int a, int b) {
        return Add(a,b);
    }
};