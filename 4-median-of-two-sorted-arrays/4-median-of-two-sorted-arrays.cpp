class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int x = nums1.size();
        int y = nums2.size();
        int len = x+y;
        int half = len/2;
        int s = 0,e = x;
        while(s<=e)
        {
            int mid1 = (s+e)/2;
            int mid2 = (x+y+1)/2 - mid1;
            
            
            int leftA = (mid1==0)?INT_MIN:nums1[mid1-1];
            int rightA = (mid1==x)?INT_MAX:nums1[mid1];
            
            
            int leftB = (mid2==0)?INT_MIN:nums2[mid2-1];
            int rightB = (mid2==y)?INT_MAX:nums2[mid2];
            
            
            if(leftA <= rightB && leftB <= rightA)
            {
                if(len%2==0)
                    return((double)max(leftA,leftB)+min(rightA,rightB))/2.0;
                else
                    return ((double)max(leftA,leftB));
            }
            else if(leftA>rightB)
                e=mid1-1;
            else
                s=mid1+1;
        }
        
        return 0.0;
    }
};