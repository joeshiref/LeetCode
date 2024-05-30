class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;

        for (int start = 0; start < arr.size() - 1; ++start) {
            int xorA = 0;

            for (int mid = start + 1; mid < arr.size(); ++mid) {
                xorA ^= arr[mid - 1];

                int xorB = 0;

                for (int end = mid; end < arr.size(); ++end) {
                    xorB ^= arr[end];

                    if (xorA == xorB) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};