class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int prefixSum = 0;
        mp[prefixSum] = 1;
        int subarrayCount = 0;
        int s = 0;
        for (int e = 0; e < n; ++e) {
            prefixSum += (nums[e] % 2);
            if (mp.find(prefixSum - k) != mp.end()) {
                subarrayCount += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        return subarrayCount;
    }
};