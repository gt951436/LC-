class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            mp[nums[i]]++;
        }
        int max_freq = 0;
        int count = 0;
        for (auto it : mp) {
            max_freq = max(max_freq, it.second);
        }
        for (auto it : mp) {
            if (it.second == max_freq) {
                count += it.second;
            }
        }
        return count;
    }
};