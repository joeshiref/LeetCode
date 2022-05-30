class Solution {
    public int lengthOfLastWord(String s) {
        int mx=-1;
        String str="";
        boolean flag=false;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s.charAt(i)==' ' && flag==false)
            {
                continue;
            }
            else if(s.charAt(i)==' ' && flag==true)
            {
                mx=Math.max(mx,str.length());
                break;
            }
            else if(s.charAt(i)!=' ')
            {
                flag=true;
                str+=s.charAt(i);
            }
        }
        mx=Math.max(mx,str.length());
        return mx;
    }
}