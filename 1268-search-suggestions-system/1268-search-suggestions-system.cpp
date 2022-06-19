class Solution {
public:
    
    bool startsWith(string &a,string &b)
    { 
        for(int i=0,j=0;i<a.size();i++,j++)
        {
            if(a[i]!=b[j])
            {
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        string conc="";
        vector<vector<string>>res;
        for(int i=0;i<searchWord.size();i++)
        {
            conc+=searchWord[i];
            int cnt=0;
            vector<string>tmp;
            for(int j=0;j<products.size()&&cnt<3;j++)
            {
                if(startsWith(conc,products[j]))
                {
                    cnt++;
                    tmp.push_back(products[j]);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};