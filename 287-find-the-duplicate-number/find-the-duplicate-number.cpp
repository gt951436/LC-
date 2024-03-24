class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // HARE AND TORTOISE ALGORITHM
        int s = nums[0];  //SLOW
        int f = nums[0]; //FAST

        s = nums[nums[0]];
        f = nums[nums[nums[0]]];

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