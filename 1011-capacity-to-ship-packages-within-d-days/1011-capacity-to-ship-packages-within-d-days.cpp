class Solution {
public:
    bool valid(vector<int>& weights, int days, int cap)
    {
        int cnt = 1,sum = 0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>cap)
            {
                sum=weights[i];
                cnt++;
            }
        }
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maximumWeight = INT_MIN;
        int sum = 0;
        for(auto & weight:weights)
        {
            maximumWeight=max(maximumWeight,weight);
            sum+=weight;
        }
        int s=maximumWeight,e=sum;
        int ans = -1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(valid(weights,days,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};