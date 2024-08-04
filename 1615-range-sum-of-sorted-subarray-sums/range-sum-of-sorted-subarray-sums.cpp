class Solution {
public:
    int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pfxSum;
        for (int i = 0; i < n; ++i) {
            int pSum = 0;
            for (int j = i; j < n; ++j) {
                pSum += nums[j];
                pfxSum.push_back(pSum);
            }
        }
        sort(pfxSum.begin(), pfxSum.end());
        int ans = 0;
        for (int i = left - 1; i <= right - 1; ++i) {
            ans = (ans + pfxSum[i]) % MOD;
        }
        return ans;
    }
};