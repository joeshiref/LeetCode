class Solution {
public:
    vector<vector<int>> res;
    vector<int>vec;
    void BT(int idx, vector<int>& candidates, int target)
    {
        if(target==0)
        {
            res.push_back(vec);
            return;
        }
        if(idx==candidates.size() || target < 0)
            return;
        if(target>=candidates[idx])
        {
            vec.push_back(candidates[idx]);
            BT(idx,candidates,target-candidates[idx]);
            vec.pop_back();
        }
        BT(idx+1,candidates,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        BT(0,candidates,target);
        return res;
    }
};