class Solution {
public:
    int maxArea(vector<int>& height) {
        int mx=0;
        for(int i=0,j=height.size()-1;i<height.size() && j>=0;)
        {
            int len=j-i;
            mx=max(mx,len*min(height[i],height[j]));
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return mx;                
    }
};