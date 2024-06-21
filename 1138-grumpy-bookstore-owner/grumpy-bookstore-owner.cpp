class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int maxSat = 0, initialTotalSat = 0;
        for (int i = 0; i < n; ++i) {
            initialTotalSat += (1 - grumpy[i]) * customers[i];
        }
        int maxExtra = 0;
        for (int i = 0; i < n - minutes + 1; ++i) {
            int currWinUnSat = 0; // unsatisfied customers
            for (int j = i; j < i + minutes && j < n; ++j) {
                if (grumpy[j])
                    currWinUnSat += customers[j];
            }
            maxExtra = max(maxExtra, currWinUnSat);
        }
        return initialTotalSat + maxExtra;
    }
};