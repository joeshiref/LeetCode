class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b)
    {
        return b[1]>a[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.rbegin(),boxTypes.rend(),cmp);
        int cnt=0,boxes=truckSize;
        for(int i=0;i<boxTypes.size() && boxes;i++)
        {
            cnt+=min(boxes,boxTypes[i][0])*boxTypes[i][1];
            boxes-=min(boxes,boxTypes[i][0]);
        }
        return cnt;
    }
};