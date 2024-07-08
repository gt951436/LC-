class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int i = 1;
        while (i <= n) {
            q.push(i);
            i += 1;
        }
        while (q.size() > 1) {
            int j = 1;
            while (j <= k - 1) {
                int tp = q.front();
                q.push(tp);
                q.pop();
                ++j;
            }
            q.pop();
        }
        return q.front();
    }
};