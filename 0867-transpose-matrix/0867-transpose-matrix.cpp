class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>res;
        for(int i=0;i<matrix[0].size();i++)
        {
            vector<int>tmp;
            for(int j=0;j<matrix.size();j++)
            {
                tmp.push_back(matrix[j][i]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};