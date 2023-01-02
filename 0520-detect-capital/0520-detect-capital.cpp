class Solution {
public:
    bool allCap(string str)
    {
        for(int i=0;i<str.size();i++)
        {
            if(islower(str[i]))
                return false;
        }
        return true;
    }
    bool allSmall(string str)
    {
        for(int i=0;i<str.size();i++)
        {
            if(isupper(str[i]))
                return false;
        }
        return true;
    }
    bool firstChar(string str)
    {
        if(islower(str[0]))
            return false;
        for(int i=1;i<str.size();i++)
        {
            if(isupper(str[i]))
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        
        return allCap(word) || allSmall(word) || firstChar(word);
    }
};