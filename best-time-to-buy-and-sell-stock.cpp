class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int miniSoFar=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<miniSoFar)
                miniSoFar=prices[i];
            int profitIfWeSellNow=prices[i]-miniSoFar;
            if(profitIfWeSellNow>ans)
                ans=profitIfWeSellNow;
        }
        return ans;
    }
};