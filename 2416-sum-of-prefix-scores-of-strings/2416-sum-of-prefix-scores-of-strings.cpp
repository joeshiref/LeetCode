
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
        for(auto word:words)
            ans.push_back(getCount(word));
        return ans;
    }
};