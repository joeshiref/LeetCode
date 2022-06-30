class Solution {
public:
    bool static cmp(vector<int> & p1, vector<int> & p2)
    {
        return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),cmp);
        vector<vector<int>> res;
        for (auto person : people){
            res.insert(res.begin() + person[1], person);
        }
        return res;
        
    }
};