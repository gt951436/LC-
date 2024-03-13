class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;
        if (PS(total))
            return sqrt(total);
        return -1;
    }
    bool PS(int x) {
        int sr = sqrt(x);
        return (sr * sr == x);
        return false;
    }
};