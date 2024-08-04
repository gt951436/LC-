class Solution {
    public int MOD = 1000000007;

    public int rangeSum(int[] nums, int n, int left, int right) {
        ArrayList<Integer> pfxSum = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                pfxSum.add(sum);
            }
        }
        Collections.sort(pfxSum);
        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + pfxSum.get(i)) % MOD;
        }
        return ans;
    }
}