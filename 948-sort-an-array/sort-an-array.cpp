class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> mp(100001, 0);
        for (const auto& it : nums) {
            mp[it + 50000]++;
        }
        int k = 0;
        for (int i = 0; i < 100001; ++i) {
            for (int j = 0; j < mp[i]; ++j) {
                nums[k++] = i - 50000;
            }
        }
        return nums;
    }
};