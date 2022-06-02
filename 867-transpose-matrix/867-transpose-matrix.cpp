class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int> > arr;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            vector<int>tmp;
            arr.push_back(tmp);
            for(int j=0;j<n;j++)
            {
                arr[i].push_back(matrix[j][i]);
            }
        }
        return arr;
        
    }
};