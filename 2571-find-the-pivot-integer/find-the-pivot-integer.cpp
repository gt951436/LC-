class Solution {
public:
    int pivotInteger(int n) {
        long long  total = n * (n + 1) / 2;
        if (PS(total))
            return sqrt(total);
        return -1;
    }
    bool PS(long long x) {
        if (x >= 0) {

            long long sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
};