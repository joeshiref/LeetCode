class Solution {
    public String addBinary(String a, String b) {
        
        int diff=Math.abs(a.length()-b.length());
        if(a.length()<b.length())
        {
            for(int r=0;r<diff;r++)
                a="0"+a;
        }
        else if(a.length()>b.length())
        {
            for(int r=0;r<diff;r++)
                b="0"+b;
        }
        System.out.println(a);
        System.out.println(b);
        int i=a.length()-1, j=b.length()-1;
        String collector="";
        int carry=0;
        for(;i>=0 && j>=0;i--,j--)
        {
            if(a.charAt(i)=='1' && b.charAt(j)=='1')
            {
                if(carry==1)
                    collector+='1';
                else
                    collector+='0';
                carry=1;
            }
            else if((a.charAt(i)=='1' && b.charAt(j)=='0')||(a.charAt(i)=='0' && b.charAt(j)=='1'))
            {
                if(carry==1)
                {
                    collector+='0';
                    carry=1;
                }
                else
                {
                    collector+='1';
                }
            }
            else
            {
                if(carry==1)
                {
                    collector+='1';
                    carry=0;
                }
                else
                {
                    collector+='0';
                }
            }
        }
        if(carry==1)
            collector+='1';
        String reverseString="";
        for(int f=collector.length()-1;f>=0;f--)
        {
            reverseString+=collector.charAt(f);
        }
        return reverseString;
        
    }
}