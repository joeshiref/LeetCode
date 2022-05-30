class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz=nums.size();
        
        for(int i=sz-1;i>=0;i--)
        {
            if(nums[i]==val)
            {
                int j;
                for(j=i;j<sz-1;j++)
                    swap(nums[j],nums[j+1]);
                sz--;

            }
            
        }
    return sz;   
    }
};
    