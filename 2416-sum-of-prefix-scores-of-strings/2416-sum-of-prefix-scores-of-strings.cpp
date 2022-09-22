
struct TrieNode {
    TrieNode *child[26] = {};
    int cnt = 0;
};

class Solution {
    TrieNode root;
public:
    void insert(string word)
    {
        auto node = &root;
        for(auto c:word)
        {
            if(!node->child[c-'a'])
                node->child[c-'a'] = new TrieNode();
            node->child[c-'a']->cnt++;
            node = node->child[c-'a'];
        }
    }
    int getCount(string word)
    {
        int ans=0;
        auto node = &root;
        for(auto c:word)
        {
            ans+=node->child[c-'a']->cnt;
            node = node->child[c-'a'];
        }
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        for(auto word:words)
            insert(word);        
        vector<int>ans;
        unordered_map<string,int>mp;
        for(auto word:words)
        {
            if(mp[word])
                ans.push_back(mp[word]);
            else
            {
                int val = getCount(word);
                ans.push_back(val);
                mp[word]=val;
            }
        }
            
        return ans;
    }
};