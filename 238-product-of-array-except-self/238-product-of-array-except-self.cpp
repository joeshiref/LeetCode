class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix,suffix;
        prefix.push_back(1);
        prefix.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            prefix.push_back(prefix[i]*nums[i]);
        suffix.push_back(1);
        suffix.push_back(nums[nums.size()-1]);
        for(int i=nums.size()-2,j=1;i>=0;i--,j++)
            suffix.push_back(suffix[j]*nums[i]);
        reverse(suffix.begin(),suffix.end());
        
        for(auto num:prefix)
            cout << num << " ";
        cout << endl;
        for(auto num:suffix)
            cout << num << " ";
        
        vector<int>ans;
        for(int i=1;i<=nums.size();i++)
            ans.push_back(prefix[i-1]*suffix[i]);
        return ans;
    }
};