class SeatManager {
public:
    priority_queue<int>pq;
    vector<int>reserved;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            pq.push(-i);
        vector<int> temp(n+1,0);
        reserved = temp;
    }
    
    int reserve() {
        int top=-pq.top();
        pq.pop();
        reserved[top]=1;
        return top;
    }
    
    void unreserve(int seatNumber) {
        reserved[seatNumber]=0;
        pq.push(-seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */