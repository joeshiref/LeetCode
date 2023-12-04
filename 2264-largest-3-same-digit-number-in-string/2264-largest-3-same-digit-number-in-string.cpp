class Solution {
public:
    string largestGoodInteger(string num) {
        int freq[10]={};
        for(int i=0;i<3;i++)
            freq[num[i]-'0']++;
        int s=0,e=2;
        int maxDigit=-1;
        if(freq[num[e]-'0']==3)
            maxDigit=num[e]-'0';
        
        while(e<num.size()-1)
        {
            freq[num[s]-'0']--;
            s++,e++;
            freq[num[e]-'0']++;
        
            if(freq[num[e]-'0']==3)
                maxDigit=max(maxDigit,num[e]-'0');
        }
        if(maxDigit==-1)
            return "";
        return string(3,maxDigit+'0');
    }
};