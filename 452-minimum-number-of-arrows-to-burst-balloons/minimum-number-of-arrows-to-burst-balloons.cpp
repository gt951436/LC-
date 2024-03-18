class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;
        sort(arr.begin(), arr.end());
        vector<int> prev = arr[0];
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            int csp = arr[i][0];
            int cep = arr[i][1];
            int psp = prev[0];
            int pep = prev[1];
            if (csp > pep) { // NO OVERLAPPING
                cnt++;
                prev = arr[i];
            } else { // OVERLAPPING
                prev[0] = max(psp, csp);
                prev[1] = min(pep, cep);
            }
        }
        return cnt;
    }
};