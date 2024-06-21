class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int totalSat = 0;
        for (int i = 0; i < n; ++i) {
            totalSat += (1 - grumpy[i]) * customers[i];
        }
        int unsatCustomers = 0;
        for (int i = 0; i < minutes; ++i) {
            unsatCustomers += grumpy[i] * customers[i];
        }
        int maxunsatCustomers = unsatCustomers;
        for (int i = minutes; i < n; ++i) {
            unsatCustomers += grumpy[i] * customers[i];
            unsatCustomers -= grumpy[i - minutes] * customers[i - minutes];
            maxunsatCustomers = max(maxunsatCustomers, unsatCustomers);
        }
        return maxunsatCustomers+totalSat;
    }
};