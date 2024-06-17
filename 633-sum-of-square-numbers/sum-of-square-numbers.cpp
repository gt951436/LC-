class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int)(a * a);
            if (BS(0, b, b))
                return true;
        }
        return false;
    }
    bool BS(long long s, long long e, int b) {
        if (s > e)
            return false;
        long long m = s + (e - s) / 2;
        if (m * m == b)
            return true;
        if (m * m > b) // b ka root left mein lie krta hai
            return BS(s, m - 1, b);
        return BS(m + 1, e, b);// b ka root ryt mein lie krta hai
    }
};