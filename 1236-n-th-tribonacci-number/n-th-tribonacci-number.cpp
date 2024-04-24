class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int num;
        int f = 0, s = 1, t = 1;

        for (int i = 3; i <= n; i++) {
            num = f + s + t;
            f = s;
            s = t;
            t = num;
        }
        return t;
    }
};