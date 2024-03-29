class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxEl = *max_element(nums.begin(), nums.end());
        long long ans = 0, s = 0;

        for (int e = 0; e < nums.size(); e++) {
            if (nums[e] == maxEl) {
                k--;
            }
            while (!k) {
                if (nums[s] == maxEl) {
                    k++;
                }
                s++;
            }
            ans += s;
        }
        return ans;
    }
};