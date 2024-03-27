class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1)
            return 0;

        int prd = 1;
        int subarrays = 0;
        int i = 0;
        for (int j = 0; i<n && j < n; ++j) {
            prd *= nums[j];
            while (prd >= k) {
                prd /= nums[i];
                ++i;
            }
            subarrays += (j - i + 1);
        }
        return subarrays;
    }
};