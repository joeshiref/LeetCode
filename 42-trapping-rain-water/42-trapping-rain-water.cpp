class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int>leftMax,rightMax;
        for(int i=0;i<height.size();i++)
        {
            if(!i)
                leftMax.push_back(height[i]);
            else
                leftMax.push_back(max(height[i],leftMax[i-1]));
        }
        for(int j=height.size()-1;j>=0;j--)
        {
            if(j==height.size()-1)
                rightMax.push_back(height[j]);
            else
                rightMax.push_back(max(height[j],rightMax[rightMax.size()-1]));
        }
        reverse(rightMax.begin(),rightMax.end());
        
        for(int i=0;i<height.size();i++)
            ans+=min(leftMax[i],rightMax[i])-height[i];
        
        return ans;
    }
};