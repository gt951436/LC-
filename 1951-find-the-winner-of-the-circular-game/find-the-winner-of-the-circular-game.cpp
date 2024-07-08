class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }
        while (q.size() > 1) {
            for (int j = 1; j <= k - 1; ++j) {
                int tp = q.front();
                q.push(tp);
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};