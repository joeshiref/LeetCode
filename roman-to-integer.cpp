class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        
        bool flag=false;
        int sum=0;
        sum+=mp[s[0]];
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]=='I' && s[i]=='V')
            {
                sum+=mp[s[i]];
                sum-=2;
            }
            else if(s[i-1]=='I' && s[i]=='X')
            {
                sum+=mp[s[i]];
                sum-=2;
            }
            else if(s[i-1]=='X' && s[i]=='L')
            {
                sum+=mp[s[i]];
                sum-=20;
            }
            else if(s[i-1]=='X' && s[i]=='C')
            {
                sum+=mp[s[i]];
                sum-=20;
            }
            else if(s[i-1]=='C' && s[i]=='D')
            {
                sum+=mp[s[i]];
                sum-=200;
            }
            else if(s[i-1]=='C' && s[i]=='M')
            {
                sum+=mp[s[i]];
                sum-=200;
            }
            else
            {
                sum+=mp[s[i]];
            }
        }
        
        return sum;
    }
};