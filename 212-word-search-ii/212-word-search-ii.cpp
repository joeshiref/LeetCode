struct trie{
    trie * child[26]={};
    bool isWord = 0;
};

class Solution {
public:
    trie * root;
    bool vis[20][20];
    int n,m;
    set<string>res;
    vector<string>ans;
    void insert(string word)
    {
        trie * ptr = root;
        for(auto c:word)
        {
            int cur = c - 'a';
            if(!ptr->child[cur])
                ptr->child[cur] = new trie();
            ptr = ptr->child[cur];
        }
        ptr->isWord = 1;
        
    }
    
    
    void backtrack(int x,int y,string str,vector<vector<char>>& board, trie * node)
    {
        if(x<0 || x>=n || y<0 || y>=m || board[x][y]==' ')
            return;
        
        if(node->child[board[x][y]-'a']!=NULL)
        {
            str+=board[x][y];
            node = node->child[board[x][y]-'a'];
            if(node->isWord)
                res.insert(str);
            char c=board[x][y];
            board[x][y]=' ';
            backtrack(x+1,y,str,board,node);
            backtrack(x,y+1,str,board,node);
            backtrack(x-1,y,str,board,node);
            backtrack(x,y-1,str,board,node);
            board[x][y]=c;
        }
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new trie();
        for(auto word:words)
            insert(word);
        n = board.size();
        m = board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                backtrack(i,j,"",board,root);
        }
        for(auto word:res)
            ans.push_back(word);
        return ans;
    }
};