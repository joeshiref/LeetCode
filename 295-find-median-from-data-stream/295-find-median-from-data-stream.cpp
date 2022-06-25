#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;



typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class MedianFinder {
public:
    ordered_set st;
    
    void addNum(int num) {
        st.insert(num);
    }
    
    double findMedian() {
        //odd size
        if(st.size()&1)
        {
            int half=st.size()/2;
            return *st.find_by_order(half);
        }
        else
        {
            int half=st.size()/2;
            return (*st.find_by_order(half) + *st.find_by_order(half-1))/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */