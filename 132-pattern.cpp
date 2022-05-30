class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        int lastElement=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<lastElement)
                return true;
            while(!st.empty() && st.top()<arr[i])
            {
                lastElement=st.top();
                st.pop();
            }
            st.push(arr[i]);
        }
        return false;
    }
};