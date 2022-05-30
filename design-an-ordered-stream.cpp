class OrderedStream {
    
private:
    int idx;
    int sz;
    vector<string>v;
public:
    OrderedStream(int n) {
        sz=n;
        idx=0;
        v.resize(n);
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string>tmp;
        v[idKey-1]=value;
        for(;idx<sz&&v[idx]!="";idx++)
        {
            tmp.push_back(v[idx]);
        }
        return tmp;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */