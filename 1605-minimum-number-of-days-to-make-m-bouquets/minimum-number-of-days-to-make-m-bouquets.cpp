class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int start_day = 1;
        int end_day = *max_element(bloomDay.begin(), bloomDay.end());
        int minDays = -1;
        while (start_day <= end_day) {
            int mid_day = start_day + (end_day - start_day) / 2;
            if (canMakeBqt(bloomDay, mid_day, k)>=m) {
                minDays = mid_day;
                end_day = mid_day - 1;
            } else {
                start_day = mid_day + 1;
            }
        }
        return minDays;
    }
    int canMakeBqt(vector<int>& bloomDay, int day, int k) {
        int bq_cnt = 0;
        int fl_cnt = 0; // k flower chahiye tabhi bouqet bnega
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= day) {
                fl_cnt++;
            } else {
                fl_cnt = 0;
            }
            if (fl_cnt == k) {
                fl_cnt = 0; // reset krdiya
                bq_cnt++;
            }
        }
        return bq_cnt;
    }
};