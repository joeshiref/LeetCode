class Solution {
public:
    
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(auto price:costs){
            if(price<=coins)
            {
                coins-=price;
                cnt++;
            }
        }
        return cnt;
    }
};