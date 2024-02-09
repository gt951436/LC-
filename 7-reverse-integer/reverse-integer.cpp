class Solution {
public:
    int reverse(int x) {
        bool is_neg = false;
        if (x < 0) {
            is_neg = true;
            x = abs(x);
        }
        long result = 0;
        while (x > 0) {
            result = (result * 10) + (x % 10);
            x = x / 10;
        }
        if (result > INT_MAX || result < INT_MIN) {
            return 0;
        }
        if (is_neg) {
            return result * -1;
        }
        return int(result);
    }
};