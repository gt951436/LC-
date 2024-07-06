class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2 * (n - 1);
        int effectiveTime = time % cycle;
        if (effectiveTime <= n - 1) {
            return effectiveTime + 1;
        }
        return (n - 1) + (n - effectiveTime);
    }
};