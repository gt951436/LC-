class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> deg(n, 0); // degree of each city
        for (auto it: roads) {
            deg[it[0]]++;
            deg[it[1]]++; // populate the deg array
        }
        sort(deg.begin(), deg.end());
        long long val = 1;
        long long totalImp = 0;
        for (long long it : deg) {
            totalImp += (val * it);
            val++;
        }
        return totalImp;
    }
};