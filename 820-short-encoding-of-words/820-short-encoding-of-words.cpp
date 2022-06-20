class Solution {
public:
    bool static cmp (string &a,string &b)
    {
        return (a.size()<b.size());
    }
    bool containsAsSuffix(string &a,string &b)
    {
        for(int i=a.size()-1,j=b.size()-1;i>=0;i--,j--)
        {
            if(a[i]!=b[j])
                return false;
        }
        return true;
            
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(containsAsSuffix(words[i],words[j]))
                    words[i]="";
            }
        }
        int cnt=0;
        for(auto s:words)
        {
            if(s.size())
            {
                cnt++;
                cnt+=s.size();
            }
        }
        return cnt;
    }
};