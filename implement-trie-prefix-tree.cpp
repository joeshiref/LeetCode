class TrieNode
{
    
public:
    TrieNode* letters[26];
    bool isLeaf;
    TrieNode()
    {
        memset(letters,0,sizeof(letters));
        isLeaf=false;
    }
};


class Trie {
    TrieNode*root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * cur = root;
        for(int i=0;i<word.size();i++)
        {
            TrieNode*node = cur->letters[word[i]-'a'];
            if(node==0)
            {
                node=new TrieNode();
                cur->letters[word[i]-'a']=node;
            }
            cur=node;
        }
        cur->isLeaf=true;
        
    }
    
    bool search(string word) {
        TrieNode * cur = root;
        for(int i=0;i<word.size();i++)
        {
            TrieNode*node=cur->letters[word[i]-'a'];
            if(node==NULL)
                return false;
            cur=node;
        }
        return cur->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for(int i=0;i<prefix.size();i++)
        {
            TrieNode*node=cur->letters[prefix[i]-'a'];
            if(node==NULL)
                return false;
            cur=node;
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