class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4)
            return 0;
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        // last 3 elements deleted
        minDiff = min(minDiff, nums[n - 4] - nums[0]);
        // starting 3 elements deleted
        minDiff = min(minDiff, nums[n - 1] - nums[3]);
        // starting 1 element and last 2 elements deleted
        minDiff = min(minDiff, nums[n - 3] - nums[1]);
        // starting 2 elements and last 1 element deleted
        minDiff = min(minDiff, nums[n - 2] - nums[2]);

        return minDiff;
    }
};