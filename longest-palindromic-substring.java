class Solution {
    public int expandAroundTheCenter(String s,int left,int right)
    {
        while(left>=0 && right<s.length()&&s.charAt(left)==s.charAt(right))
        {
            left--;
            right++;
        }
        return (right-left)-1;
    }
    public String longestPalindrome(String s) {
        int start=0,end=0;
        for(int i=0;i<s.length();i++)
        {
            int c1=expandAroundTheCenter(s,i,i);
            int c2=expandAroundTheCenter(s,i,i+1);
            int mx=Math.max(c1,c2);
            if(mx>(end-start))
            {
                start = i - (mx - 1) / 2;
                end = i + mx / 2;
            }
        }
        return s.substring(start, end + 1);
    }
}