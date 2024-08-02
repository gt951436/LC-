class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totOnes = count(nums.begin(), nums.end(), 1);
        if (totOnes == 0) {
            return 0;
        }
        int currOnesCnt = 0;
        for (int i = 0; i < totOnes; ++i) {
            if (nums[i] == 1)
                ++currOnesCnt;
        }
        int maxOnesCnt = currOnesCnt;
        for (int i = 1; i < n; ++i) {
            if (nums[i - 1] == 1) {
                --currOnesCnt;
            }
            if (nums[(i + totOnes - 1) % n] == 1) {
                ++currOnesCnt;
            }
            maxOnesCnt = max(maxOnesCnt, currOnesCnt);
        }
        return totOnes - maxOnesCnt;
    }
};