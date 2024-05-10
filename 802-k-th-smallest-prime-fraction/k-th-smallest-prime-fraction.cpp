class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<vector<double>> pq;
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double fr = (double)arr[i] / arr[j];
                pq.push(vector<double>{fr, (double)arr[i], (double)arr[j]});

                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        auto res = pq.top();
        vector<int> ans(2);
        ans[0] = res[1];
        ans[1] = res[2];
        return ans;
    }
};