class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int len = piles.size() / 3;
        sort(piles.begin(),piles.end());
        int sum = 0;
        for(int i=piles.size()-2;len--;i-=2)
            sum+=piles[i];
        return sum;
    }
};