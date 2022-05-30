class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int maxi=-1;
        while(s<e)
        {
            int area=(e-s)*min(height[s],height[e]);
            if(height[s]<=height[e])
                s++;
            else
                e--;
            maxi=max(maxi,area);
        }
        return maxi;
    }
};