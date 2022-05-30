class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int s=1;
        int e=A.size()-2;
        int ans;
        while(s<=e)
        {
            int mid=(e+s)/2;
            if(A[mid]>A[mid-1] && A[mid]>A[mid+1])
            {
                ans=mid;
                break;
            }
            else if(A[mid]>A[mid-1] && A[mid]<A[mid+1])
                s=mid+1;
            else if(A[mid]<A[mid-1] && A[mid]>A[mid+1])
                e=mid-1;
        }
        return ans;
    }
};