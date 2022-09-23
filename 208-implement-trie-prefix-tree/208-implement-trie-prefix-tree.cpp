struct trie{
    trie *child[26] = {};
    bool isLeaf = 0;
};
class Trie {
    trie * root;
public:
    Trie() {
        root = new trie();
    }
    void insert(string word) {
        trie * ptr = root;
        for(auto c:word)
        {
            int cur = c - 'a';
            if(!ptr->child[cur])
                ptr->child[cur] = new trie();
            ptr = ptr->child[cur];
        }
        ptr->isLeaf = 1;
    }
    
    bool search(string word) {
        trie * ptr = root;
        for(auto c:word)
        {
            int cur = c - 'a';
            if(!ptr->child[cur])
                return false;
            ptr = ptr->child[cur];
        }
        return ptr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        trie * ptr = root;
        for(auto c:prefix)
        {
            int cur = c - 'a';
            if(!ptr->child[cur])
                return false;
            ptr = ptr->child[cur];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */