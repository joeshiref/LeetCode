class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        string collector = "";
        for(auto &c:s)
        {
            if(c==' ')
            {
                if(collector.size())
                {
                    vec.push_back(collector);
                    collector = "";
                }
                continue;
            }
            collector+=c;
        }
        if(collector.size())
        {
            vec.push_back(collector);
            collector = "";
        }
        string ans="";
        for(int i=vec.size()-1;i>=0;i--)
        {
            ans+=vec[i];
            if(i>0)
                ans+=' ';
        }
        return ans;
    }
};