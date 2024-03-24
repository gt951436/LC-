class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // HARE AND TORTOISE ALGORITHM
        int s = nums[0], f = nums[0]; // SLOW , FAST

        s = nums[s];
        f = nums[nums[f]];

        while (s != f) { // cycle detection
            s = nums[s];
            f = nums[nums[f]];
        }
        f = nums[0];

        while (f != s) { // l1+l2 = n*k ===> l1 = n*k - l2
            s = nums[s];
            f = nums[f];
        }
        return f; // or slow
    }
};