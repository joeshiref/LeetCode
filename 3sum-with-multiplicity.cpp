class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int >mp;
        
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int rem=target-(arr[i]+arr[j]);
                cnt+=mp[rem];
            }
            mp[arr[i]]++;
            cnt%=1000000007;
        }
        return cnt;
    }
};