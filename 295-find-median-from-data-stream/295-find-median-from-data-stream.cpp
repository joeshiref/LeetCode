#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
class MedianFinder {
public:
    
    int sz;
    ordered_set st;
    MedianFinder() {
        sz=0;
    }
    
    void addNum(int num) {
        st.insert(num);
        sz++;
    }
    
    double findMedian() {
        if(sz&1)
            return *st.find_by_order(sz/2);
        else
        {
            double a = *st.find_by_order((sz-1)/2);
            double b = *st.find_by_order(sz/2);
            cout << a << " " << b << endl;
            return (a+b)/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */