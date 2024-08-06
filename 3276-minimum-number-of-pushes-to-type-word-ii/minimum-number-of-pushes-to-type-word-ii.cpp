class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> f;
        for (char ch : word) {
            f[ch]++;
        }
        priority_queue<int> pq;
        for (auto it : f) {
            pq.push(it.second);
        }
        int timesCnt = 0;
        int i = 0;
        while (!pq.empty()) {
            timesCnt += ((i / 8) + 1) * pq.top();
            pq.pop();
            i += 1;
        }
        return timesCnt;
    }
};