class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        int max_len = 1;
        int s = 0;
        int e = 0;
        while (e < n) {
            if (mp[nums[e]] <= k) {
                mp[nums[e]]++;
            }
            while (e < n && mp[nums[e]] > k) {

                mp[nums[s]]--;
                s++;
            }
            max_len = max(max_len, e - s + 1);
            e++;
        }
        return max_len;
    }
};