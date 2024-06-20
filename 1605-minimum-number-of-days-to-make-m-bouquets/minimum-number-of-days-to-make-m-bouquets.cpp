class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL*m * 1LL*k > bloomDay.size()) {
            return -1;
        }
        long long l = 1;
        long long r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            int bq = 0, fl_cnt = 0;
            for (int i = 0; i < bloomDay.size(); ++i) {
                if (bloomDay[i] <= mid) {
                    fl_cnt++;
                    if (fl_cnt == k) {
                        bq++;
                        fl_cnt = 0;
                    }
                } else {
                    fl_cnt = 0;
                }
            }
            if (bq >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};