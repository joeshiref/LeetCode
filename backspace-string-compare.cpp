
class Solution
{
public:
    bool isValid(char a,char b)
    {
        if(isalpha(a) && !isalpha(b)
                || !isalpha(a) && isalpha(b)
                || (isalpha(a) && isalpha(b) && a!=b) )
            return false;
        return true;
    }
    bool backspaceCompare(string s, string t)
    {
        int firstCounter=0,secondCounter=0;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i]=='#')
                firstCounter++;
            else
            {
                if(firstCounter)
                {
                    s[i]='-';
                    firstCounter--;
                }
            }
        }
        for(int i=t.size()-1; i>=0; i--)
        {
            if(t[i]=='#')
                secondCounter++;
            else
            {
                if(secondCounter)
                {
                    t[i]='-';
                    secondCounter--;
                }
            }
        }
        cout << s << " " << t << endl;
        bool flag=true,first=false,second=false;
        int i=0,j=0;
        for(; i<s.size()&&j<t.size();)
        {
            if(!isalpha(s[i]))
                i++;
            else if(isalpha(s[i]))
                first=true;

            if(!isalpha(t[j]))
                j++;
            else if(isalpha(t[j]))
                second=true;

            if(first && second)
            {
                if(s[i]!=t[j])
                {
                    flag=false;
                    break;
                }
                else
                    i++,j++;
                first=false,second=false;
            }
        }
        if(i<s.size())
        {
            for(;i<s.size();i++)
            {
                if(isalpha(s[i]))
                    return false;
            }
        }
        if(j<t.size())
        {
            for(;j<t.size();j++)
            {
                if(isalpha(t[j]))
                    return false;
            }
        }
        return flag;

    }
};