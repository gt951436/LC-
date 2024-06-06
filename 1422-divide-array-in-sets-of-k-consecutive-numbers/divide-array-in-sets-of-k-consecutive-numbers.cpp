class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k)
            return false;

        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        sort(nums.begin(), nums.end());
        for (int it : nums) {
            if (mp[it] > 0) {
                for (int i = it; i < it + k; ++i) {
                    mp[i]--;
                    if (mp[i] < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};