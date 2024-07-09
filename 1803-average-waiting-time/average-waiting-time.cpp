class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double totWT = 0.0; // int totWT = 0; // (int) is not working!
        int ct = 0;
        for (int i = 0; i < n; ++i) {
            ct = max(ct, customers[i][0]) + customers[i][1];
            totWT += (ct - customers[i][0]);
        }
        totWT /= n;
        return totWT;
    }
    //  O(N)-->TC
    // O(1)-->SC
};