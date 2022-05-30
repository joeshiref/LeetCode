class RecentCounter {
public:
    deque<int>dq;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        dq.push_back(t);
        int f=dq.front();
        int start=t-3000;
        while(f<start)
        {
            dq.pop_front();
            f=dq.front();
        }
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */