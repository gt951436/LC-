class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Building frequency map
        int freq[26] = {0};
        for (char &ch : tasks) {
            freq[ch - 'A']++;
        }

        // pq to store fqs
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int ans = 0;
        // Process tasks until the pq is empty
        while (!pq.empty()) {
            int processes = n + 1;
            vector<int> temp;
            int cnt = 0;
            // Execute tasks in each cycle
            while (processes-- && !pq.empty()) {
                if (pq.top() > 1) {
                    temp.push_back(pq.top() - 1);
                }
                pq.pop();
                cnt++;
            }
            // Restore updated frequencies to the heap
            for (int &it : temp) {
                pq.push(it);
            }
            // Add time for the completed cycle
            ans += (pq.empty() ? cnt : n + 1);
        }
        return ans;
    }
};