class LRUCache {
public:
    list<pair<int,int> >lst;
    unordered_map<int, list<pair<int,int>>::iterator >mp;
    int size;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        lst.splice(lst.begin(),lst,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            lst.splice(lst.begin(),lst,mp[key]);
            mp[key]->second=value;
            return;
        }
        else if(size == lst.size())
        {
            auto delKey = lst.back().first;
            lst.pop_back();
            mp.erase(delKey);
        }
        lst.push_front({key,value});
        mp[key]=lst.begin();
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */