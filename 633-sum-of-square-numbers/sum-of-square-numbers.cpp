class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a) {
            int b = c -(int)(a*a);
            if(sqRoot(b))
            return true;
        }
        return false;
    }
    bool sqRoot(int x) {
        if (x < 0) {
            return false;
        }
        long long SQRT = static_cast<long long>(sqrt(x));
        return (SQRT * SQRT == x);
    }
};