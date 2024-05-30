class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt = 0;
        for (int s = 0; s < arr.size() - 1; ++s) {
            int xorA = 0;
            for (int mid = s + 1; mid < arr.size(); ++mid) {
                xorA ^= arr[mid - 1];
                int xorB = 0;
                for (int e = mid; e < arr.size(); ++e) {
                    xorB ^= arr[e];
                    if (xorA == xorB) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};