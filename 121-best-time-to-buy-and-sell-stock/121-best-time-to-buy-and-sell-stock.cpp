class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=prices[prices.size()-1];
        int difference = 0;
        for(int i=prices.size()-2;i>=0;i--)
        {
            mx = max(mx,prices[i]);
            difference = max(difference,mx-prices[i]);
        }
        return difference;
    }
};