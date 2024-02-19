class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n>0) {
            if (n & (n - 1))
                return false;

            return true;
        }
        return false;
    }
};