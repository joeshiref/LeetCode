class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(mid==0 || (arr[mid-1]<arr[mid] && arr[mid+1]>arr[mid]))
                s=mid+1;
            else if(mid==arr.size()-1 || (arr[mid-1]>arr[mid] && arr[mid+1]<arr[mid]))
                e=mid-1;
            else if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
            {
                ans=mid;
                break;
            }
        }
        return ans;
    }
};