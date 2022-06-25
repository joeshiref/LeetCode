class SeatManager {
public:
    set<int> st = {};
    int cur = 1;
    
    SeatManager(int n) {}
    
    int reserve() {
        if (st.size()) {
            int res = *begin(st);
            st.erase(begin(st));
            return res;
        } else {
            return cur++;
        }
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};