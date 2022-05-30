class Solution {
public:
    int maxSubarraySum(int sum[],int k, int row)
    {
        int curSum = 0, curMax = INT_MIN;
        set<int> sumSet;
        sumSet.insert(0);
        for (int r = 0; r < row; ++r)
        {

            curSum += sum[r];
            auto it = sumSet.lower_bound(curSum - k);
            if (it != sumSet.end())
                curMax = max(curMax,curSum - *it);
            sumSet.insert(curSum);
        }
        return curMax;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        int tmp[100]= {};
        int cols=matrix[0].size();
        int maxSum=INT_MIN;
        for(int L=0; L<cols; L++)
        {
            memset(tmp,0,sizeof(tmp));
            for(int R=L; R<cols; R++)
            {
                for(int i=0; i<matrix.size(); i++)
                    tmp[i]+=matrix[i][R];
                int curSum=maxSubarraySum(tmp,k,matrix.size());
                maxSum=max(maxSum,curSum);
            }
        }
        return maxSum;
    }


};