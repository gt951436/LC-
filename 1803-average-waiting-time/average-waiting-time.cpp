class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<int> CT(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                CT[i] = customers[i][0] + customers[i][1];
            else {
                if (CT[i - 1] < customers[i][0])
                    // AT[i] > CT[i-1]
                    CT[i] = customers[i][0] + customers[i][1];
                else
                    CT[i] = CT[i - 1] + customers[i][1];
            }
        }
        // int totWT = 0; // (int) is not working!
        double totWT = 0.0;
        for (int i = 0; i < n; ++i) {
            totWT += (CT[i] - customers[i][0]);
        }
        totWT /= n;
        return totWT;
    }
};