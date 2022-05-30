class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size();
        
        for(int i=0;i<n;i++)
        {
            reverse(A[i].begin(),A[i].end());
            for(int j=0;j<A[i].size();j++)
                A[i][j]^=1;
        }
        return A;
    }
};