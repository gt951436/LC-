class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        // exactly k = atmost(k)-atmost(k-1)
        return atmost(k, nums) - atmost(k - 1, nums);
    }
    int atmost(int k, vector<int>& nums) {
        int s = 0, e = 0;
        int ans = 0;
        for (e = 0; e < nums.size(); ++e) {
            if (nums[e] % 2 != 0) {
                k -= 1;
            }
            while (k < 0) {
                if (nums[s] % 2 != 0)
                    k++;
                s++;
            }
            ans += (e - s + 1);
        }
        return ans;
    }
};