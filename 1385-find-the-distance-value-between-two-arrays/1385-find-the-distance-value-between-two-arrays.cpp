class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = arr1.size();
        for (int i = 0; i < arr1.size(); i++) {
            int l = 0, r = arr2.size() - 1, m, dst;
            while (l <= r) {
                m = (r - l) / 2 + l;
                dst = arr2[m] - arr1[i];
                if (dst <= d && -d <= dst) {
                    ans--;
                    break;
                } else if (dst > d) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return ans;
    }
};