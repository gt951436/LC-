class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1, r = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int len = 0, bq = 0;
            for(int i = 0; i < bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) {
                    len++;
                    if(len >= k) {
                        len = 0;
                        bq++;
                    }
                } else {
                    len = 0;
                }
            }
            if(bq >= m) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};