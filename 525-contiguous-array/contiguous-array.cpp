class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                sum--;
            else
                sum++;
            if (sum == 0) {
                len = i + 1;
            } else if (mp.find(sum) != mp.end()) {
                len = max(len, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return len;
    }
};