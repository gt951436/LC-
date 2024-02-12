class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        for (auto [x, y] : mp) {
            if (y > (nums.size() / 2)) {
                return x;
            }
        }
        return -1;
    }
};