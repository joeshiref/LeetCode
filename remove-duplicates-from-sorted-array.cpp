class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int sz=nums.size();
        for(int i=sz-1;i>0;i--)
        {
            if(nums[i]==nums[i-1])
            {
                if(i==sz-1)
                {
                    //nums.pop_back();
                    sz--;
                }
                else
                {
                    sz--;
                    for(int j=i;j<sz;j++)
                    {
                        swap(nums[j],nums[j+1]);
                    }
                }
            }
        }
        
        return sz;
    }
};