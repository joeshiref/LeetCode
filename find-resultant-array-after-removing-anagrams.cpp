class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>tmp=words;
        for(auto &s:words)
            sort(s.begin(),s.end());
        for(int i=words.size()-1;i>0;i--)
        {
            if(words[i]==words[i-1])
                words[i]="-1";
        }
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            if(words[i]!="-1")
                ans.push_back(tmp[i]);
        }
        
        return ans;
        
    }
};