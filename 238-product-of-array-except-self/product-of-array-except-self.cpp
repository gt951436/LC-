class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int pd = 1;
        int zeroes = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                zeroes++;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0)
                pd *= nums[i];
        }
        if (zeroes == 0) {
            for (int i = 0; i < n; ++i) {
                nums[i] = pd / nums[i];
            }
        } else if (zeroes == 1) {
            for (int i = 0; i < n; ++i) {
                if (nums[i] == 0)
                    nums[i] = pd;
                else
                    nums[i] = 0;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                nums[i] = 0;
            }
        }

        return nums;
    }
};