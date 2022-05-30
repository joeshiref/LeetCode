class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
                pq.push(matrix[i][j]*-1);
        }
        int v=k-1;
        while(v--)
            pq.pop();
        return pq.top()*-1;
    }
};