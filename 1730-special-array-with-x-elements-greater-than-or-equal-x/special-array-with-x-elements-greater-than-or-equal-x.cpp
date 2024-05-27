class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            int x = solve(nums, i);
            if (n - x == i) {
                return i;
            }
        }
        return -1;
    }
    int solve(vector<int>& nums, int i) {
        int s = 0, e = nums.size() - 1;
        int idx = nums.size();
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] >= i) {
                idx = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return idx;
    }
};