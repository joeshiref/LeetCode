class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>prefix(n+1,0),suffix(n+1,0);
        for(int i=1;i<=n;i++)
            prefix[i]=prefix[i-1]+cardPoints[i-1];
        for(int i=n-1,j=n-1;i>=0;i--,j--)
            suffix[i]=suffix[i+1]+cardPoints[j];
        int leftSum=prefix[k];
        int rightSum=0;
        int mx=leftSum+rightSum;
        for(int i=n-1,j=k-1;j>=0 && i>=0;i--,j--)
        {
            rightSum=suffix[i];
            leftSum-=cardPoints[j];
            mx=max(mx,rightSum+leftSum);
        }
        return mx;
        
    }
};