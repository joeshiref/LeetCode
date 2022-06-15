class Solution {
public:
    static bool compare(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string, int> dp; 
        sort(words.begin(), words.end(), compare);
        int len = 1; 
        for(auto word:words) 
        {
            dp[word]=1; 
            for(int i=0; i<word.length(); i++) 
            {
                
                string pred = word.substr(0,i) + word.substr(i+1); 
                
                if(dp.find(pred) != dp.end()) 
                {
                    dp[word] = dp[pred]+1; 
                    len = max(len, dp[word]);
                }
            }
        }
        return len;    
    }
};