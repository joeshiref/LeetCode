class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1000000007;
        stack<int>indexes;
        long long sum=0;
        for(int i=0;i<=arr.size();i++)
        {
            while(!indexes.empty() && (i==arr.size() || arr[indexes.top()]>= arr[i] ))
            {
                long long idx = indexes.top();
                indexes.pop();
                long long left = indexes.empty()?-1 : indexes.top();
                long long right = i;
                long long sz = ((idx - left) * (right - idx)) % MOD;
                sum+=((sz% MOD)*(arr[idx]% MOD))%MOD;
                sum%=MOD;
            }
            
            indexes.push(i);
        }
        return sum;
    }
};