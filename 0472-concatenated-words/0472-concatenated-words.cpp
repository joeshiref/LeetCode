struct trie {
	trie * child[26] = {};
	bool isLeaf = 0;
};

class Solution {
    trie * root;

public:
    void insert(string word)
    {
        trie * node = root;
        for (auto c : word)
        {
            int cur = c - 'a';
            if (node->child[cur]==NULL)
                node->child[cur] = new trie();
            node = node->child[cur];
        }
        node->isLeaf = 1;
    }
    bool countWords(string word, int idx, int count)
    {
        if (idx == word.size())
            return count >= 2;
        trie * ptr = root;
        for (int i = idx; i < word.size(); i++)
        {
            int cur = word[i] - 'a';
            if (!ptr->child[cur])
                return false;
            ptr = ptr->child[cur];
            if (ptr->isLeaf)
            {
                if (countWords(word, i + 1, count + 1))
                    return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new trie();
        vector<string> ans;
        for (auto word : words)
        {
            insert(word);
        }
        for(auto word:words)
        {
            if(countWords(word,0,0))
                ans.push_back(word);
        }
        
        return ans;
    }
};