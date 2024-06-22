class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> uniqueSubarrays;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            vector<int> subarray;
            int countDivisible = 0;
            for (int j = i; j < n; ++j) {
                subarray.push_back(nums[j]);
                if (nums[j] % p == 0) {
                    ++countDivisible;
                }
                if (countDivisible > k) {
                    break;
                }
                string subarrayStr = to_string(subarray[0]);
                for (int idx = 1; idx < subarray.size(); ++idx) {
                    subarrayStr += "," + to_string(subarray[idx]);
                }
                uniqueSubarrays.insert(subarrayStr);
            }
        }
        return uniqueSubarrays.size();
    }
};