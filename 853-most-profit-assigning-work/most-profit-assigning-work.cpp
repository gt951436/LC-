class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> pd;
        for (int i = 0; i < worker.size(); ++i) {
            pd.push_back({difficulty[i], profit[i]});
        }
        sort(worker.begin(), worker.end());
        sort(pd.begin(), pd.end());
        int i = 0;
        int ans = 0;
        int maxi = 0;
        for (int it : worker) {
            while (it >= pd[i].first && i < worker.size()) {
                maxi = max(maxi, pd[i].second);
                i++;
            }
            ans += maxi;
        }
        return ans;
    }
};