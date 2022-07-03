class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>v;
        for(int i=1;i<nums.size();i++)
            v.push_back(nums[i]-nums[i-1]);    
        int cnt=0,prev=2;
         for(auto num:v)
         {
             if(num>0 && (prev==0||prev==2))
             {
                 cnt++;
                 prev=1;
             }
             else if(num<0 && (prev==1||prev==2))
             {
                 cnt++;
                 prev=0;
             }
         }
        return cnt+1;
        
    }
};