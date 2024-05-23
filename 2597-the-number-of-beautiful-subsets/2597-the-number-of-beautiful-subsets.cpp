class Solution {
public:
    
    vector<int>vec;
    unordered_map<int,int>freq;
    
    int solve(int idx,vector<int>& nums, int k)
    {
        if(idx == nums.size())
        {
            return 1;
        }
        int cnt = solve(idx+1,nums,k);
        int a = nums[idx] - k;
        if(!freq[a])
        {
            freq[nums[idx]]++;
            cnt+=solve(idx+1,nums,k);
            freq[nums[idx]]--;
        }
        return cnt;
        
    }
    
    
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return solve(0,nums,k)-1;
    }
};