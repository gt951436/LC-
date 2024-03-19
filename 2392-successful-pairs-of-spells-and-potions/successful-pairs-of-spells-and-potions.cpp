class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
         int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; ++i) {
            int l = 0;
            int r = m - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if ((long)spells[i] * (long)potions[mid] >= success) {
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            ans[i] = m - r - 1;
        }
        return ans;
    }
};