class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        int i=0; 
        int j=0;
        vector<vector<int>> ans;
        while(i<n && j<m) {
            int front = max(firstList[i][0], secondList[j][0]); //To check overlapping we can use this nice trick 
            int back = min(firstList[i][1], secondList[j][1]);
            if(back-front >= 0) {
                ans.push_back({front, back}); //if they overlap then push the overlapped part
            }
            if(firstList[i][1] < secondList[j][1]) { //Now increment the counter corresponding to the interval that ends first because it won't have any overlapping later
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};


        
  
