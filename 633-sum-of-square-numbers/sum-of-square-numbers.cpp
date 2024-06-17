class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a) {
            double b = sqrt(c -(long long)(a*a));
            if(b==(int)b)
            return true;
        }
        return false;
    }
    // bool sqRoot(int x) {
    //     if (x < 0) {
    //         return false;
    //     }
    //     long long SQRT = static_cast<long long>(sqrt(x));
    //     return (SQRT * SQRT == x);
    // }
};