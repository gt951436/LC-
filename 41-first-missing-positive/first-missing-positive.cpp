class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int isOne = 0;
        int n = nums.size();

        // check if 1 is present or not
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                isOne = 1;
                break;
            }
        }
        if (!isOne)
            return 1; // if 1 is not present
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            int idx = num - 1;
            if (nums[idx] < 0)
                continue;
            else
                nums[idx] *= -1;
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0)
                return (i + 1);
        }
        return (n + 1); // all [1,n] are present
    }
};