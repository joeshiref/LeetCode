class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, maximum = INT_MIN;
        for(auto num:gain)
        {
            maximum = max (maximum, cur);
            cur += num;
        }
        maximum = max (maximum, cur);
        return maximum;
    }
};