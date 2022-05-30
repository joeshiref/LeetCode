class Solution {
public:
    int max(int a,int b)
    {
        return (a>b)?a:b;
    }
    
    int maxProduct(vector<string>& words) {
        vector<int>nums;
        for(int i=0;i<words.size();i++)
        {
            bitset<32>bt;
            for(int j=0;j<words[i].size();j++)
            {
                bt[words[i][j]-'a']=1;
            }
            nums.push_back(bt.to_ulong());
        }
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if((nums[i]&nums[j])==0)
                    mx=max(words[i].size()*words[j].size(),mx);
            }
        }
        return mx;
    }
};