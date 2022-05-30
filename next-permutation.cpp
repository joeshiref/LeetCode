class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)
            return;
        bool ok=true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                ok=false;
                break;
            }
        }
        if(ok)
            sort(nums.begin(),nums.end());
        else
        {
            
            int idx1=-1,idx2=-1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                idx1=i;
                idx2=i-1;
                break;
            }
        }
        if(idx1==-1 && idx2==-1)
            return;
        int minMax=INT_MAX;
        int idxSwap=-1;
        for(int i=idx2;i<nums.size();i++)
        {
            if(nums[i]>nums[idx2])
            {
                if(nums[i]<minMax)
                {
                    minMax=nums[i];
                    idxSwap=i;
                }
            }
        }
            //cout << idx2 << " " << idxSwap << endl;
        swap(nums[idx2],nums[idxSwap]);
        sort(nums.begin()+idx1,nums.end());
        
        
        }
        
    }
};