class Solution {
    public int[] plusOne(int[] digits) {
        boolean flag=false;
        for(int i=digits.length-1;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]++;
                flag=true;
                break;
            }
            else
                digits[i]=0;
        }
        if(!flag)
        {
            int [] res= new int[digits.length+1];
            res[0]=1;
            
            return res;
        }
        return digits;
    }
}