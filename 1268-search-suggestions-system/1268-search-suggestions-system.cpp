struct trie{
    bool isLeaf;
    trie * child[26];
    trie()
    {
        memset(child,0,sizeof(child));
        isLeaf = 0;
    }
    void insert(char *str)
    {
        if(*str=='\0')
            isLeaf = 1;
        else
        {
            int cur = *str - 'a';
            if(child[cur]==0)
                child[cur]=new trie();
            child[cur] -> insert(str+1);
        }
    }
    bool prefix(char *str)
    {
        if(*str=='\0')
            return true;
        else
        {
            int cur = *str - 'a';
            if(child[cur]==0)
                return false;
            return child[cur] -> prefix(str+1);
        }
    }
};


class Solution {
public:
    bool prefix(string s1, string s2)
    {
        if(s1.size()>s2.size())
            return false;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
                return false;
        }
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        for(auto pro:products)
            cout << pro << " ";
        cout << endl;
        vector<vector<string>> ans;
        string str="";
        int start,bsStart=0;
        for(int i=0;i<searchWord.size();i++)
        {
            str+=searchWord[i];
            start = lower_bound(products.begin()+bsStart,products.end(),str) - products.begin();
            
            vector<string>tmp;
            for(int j=start;j<products.size() && tmp.size()<3 && !products[j].compare(0,str.length(),str) ;j++)
                tmp.push_back(products[j]);
            
            ans.push_back(tmp);
            bsStart=start;
        }
        
        return ans;
    }
};