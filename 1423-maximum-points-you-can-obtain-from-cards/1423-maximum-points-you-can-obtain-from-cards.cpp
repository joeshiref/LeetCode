class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        int mx=sum;
        int total = sum;
        for(int i=k-1,j=n-1;i>=0;i--,j--)
        {
            total = total - cardPoints[i] + cardPoints[j];
            mx=max(mx,total);
        }
        return mx;
    }
};