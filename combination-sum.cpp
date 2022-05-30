class Solution {
public:
    
    vector<vector<int>>ans;
    vector<int>tmp;
    void solve(vector<int>& candidates, int target,int idx)
    {
        if(target==0)
        {
            ans.push_back(tmp);
            return;
        }
        if(idx>=candidates.size())
            return;
        if(target<candidates[idx])
            solve(candidates,target,idx+1);
        else
        {
            tmp.push_back(candidates[idx]);
            solve(candidates,target-candidates[idx],idx);
            tmp.pop_back();
            solve(candidates,target,idx+1);
        }
        
        


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        solve(candidates,target,0);
        return ans;
    }
};