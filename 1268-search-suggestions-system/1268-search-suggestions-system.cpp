
struct trie
{
	bool isLeaf;
	trie * child[26];
	vector<string>vec;
	trie()
	{
		memset(child, 0, sizeof(child));
		isLeaf = 0;
	}
	void insert(int idx, string str)
	{
		if (idx == str.size())
			isLeaf = 1;
		else
		{
			int cur = str[idx] - 'a';
			if (child[cur] == 0)
				child[cur] = new trie();
			child[cur]->vec.push_back(str);
			child[cur]->insert(idx + 1, str);
		}
	}
	vector<string> prefix(int idx, string str)
	{
		if (idx == str.size())
			return vec;
		else
		{
			int cur = str[idx] - 'a';
			if (child[cur] == 0)
				return{};
			return child[cur]->prefix(idx + 1, str);
		}
	}
};


class Solution {
public:
    int min(int x,int y)
    {
        if(x<y)
            return x;
        return y;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        
        trie root;
        vector<vector<string>> ans;
        for(auto product:products)
            root.insert(0,product);
        
        string str="";
        for(int i=0;i<searchWord.size();i++)
        {
            str+=searchWord[i];
            ans.push_back({});
            vector<string> tmp = root.prefix(0,str);
            for(int j=0;j<min(3,tmp.size());j++)
                ans[i].push_back(tmp[j]);
        }
        
        return ans;
    }
};