class Solution {
public:
    
    int lettersFreq[26];
    vector<string>vec;
    int mx;
    unordered_map<string,vector<int> >mp;
    bool canBeTaken(string str)
    {
        vector<int>freq=mp[str];
        for(auto c:str)
        {
            if(lettersFreq[c-'a']<freq[c-'a'])
                return false;
        }
        return true;
    }
    
    
    void doProcess(string str, int val)
    {
        for(auto c:str)
        {
            lettersFreq[c-'a']+=val;
        }
    }
    
    int getScore(vector<int>& score)
    {
        int res = 0;
        for(auto s:vec)
        {
            for(auto c:s)
            {
                res+=score[c-'a'];
            }
        }
        return res;
    }
    
    
    void solve(int idx, vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        if(idx == words.size())
        {
            // calculate score of the valid set
            mx = max(mx,getScore(score));
            return;
        }
        solve(idx+1,words,letters,score);
        if(canBeTaken(words[idx]))
        {
            vec.push_back(words[idx]);
            doProcess(words[idx],-1);
            solve(idx+1,words,letters,score);
            doProcess(words[idx],+1);
            vec.pop_back();
        }
    }
    
    
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(auto c:letters)
            lettersFreq[c-'a']++;
        for(auto word:words)
        {
            vector<int>vec(26,0);
            for(auto c:word)
                vec[c-'a']++;
            mp[word]=vec;
        }
        solve(0,words,letters,score);
        return mx;
    }
};