class Solution {
    public int findMin(int[] nums) {
        int s=0,e=nums.length-1;
        int n=nums.length-1;
        while(s<=e)
        {
            int mid=(e+s)/2;
            if(nums[mid]<=nums[n])
                e=mid-1;
            else
                s=mid+1;
        }
        return nums[s];
    }
}