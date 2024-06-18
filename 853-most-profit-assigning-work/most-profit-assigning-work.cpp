class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> pd(difficulty.size());
        for (int i = 0; i < difficulty.size(); ++i) {
            pd[i] = {difficulty[i], profit[i]};
        }
        auto comp = [&](pair<int, int> a, pair<int, int> b) {
            if (a.first < b.first)
                return true;
            return false;
        };
        sort(worker.begin(), worker.end());
        sort(pd.begin(), pd.end(), comp);
        int cov = 0;
        int ans = 0;
        int maxi = 0;
        for(int i=0; i<worker.size(); i++){
            int idx = bs(pd, worker[i]);
            for(int i=cov; i<=idx; i++){
                maxi = max(maxi, pd[i].second);
            }
            cov = max(0,idx);
            ans += maxi;
        }
        return ans;
    }
    int bs(vector<pair<int, int>>& pd, int val) {
        int l = 0;
        int r = pd.size() - 1;
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (pd[mid].first <= val) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};