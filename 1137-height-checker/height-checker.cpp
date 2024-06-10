class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sorted = heights;
        cnt_sort(sorted);
        int gt = 0;
        for (int i = 0; i < sorted.size(); ++i) {
            if (sorted[i] != heights[i])
                ++gt;
        }
        return gt;
    }
    void cnt_sort(vector<int>& heights) {
        map<int, int> mp;
        int mini = *min_element(heights.begin(), heights.end());
        int maxi = *max_element(heights.begin(), heights.end());
        for (int i = 0; i < heights.size(); ++i) {
            mp[heights[i]]++;
        }
        int idx = 0;
        for (int i = mini; i <= maxi; ++i) {
            while (mp[i]--) {
                heights[idx] = i;
                idx++;
            }
        }
    }
};