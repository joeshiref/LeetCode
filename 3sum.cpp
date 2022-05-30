class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(i!=0)
            {
                if(nums[i]==nums[i-1])
                    continue;
            }
            for(int L=i+1,R=nums.size()-1; L<R;)
            {
                int a=nums[i],b=nums[L],c=nums[R];
                if(a+b+c==0)
                {
                    vector<int>tmp;
                    tmp.push_back(a);
                    tmp.push_back(b);
                    tmp.push_back(c);
                    ans.push_back(tmp);
                    L++;
                    while(nums[L]==nums[L-1]&&L<nums.size()-1)
                    {
                        L++;
                    }
                }
                else if(a+b+c>0)
                    R--;
                else
                    L++;
            }
        }
        return ans;
    }
};