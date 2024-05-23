class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        sort(nums.begin(), nums.end());
        return countBeautifulSubsets(nums, k, freqMap, 0) - 1;
    }

private:
    int countBeautifulSubsets(vector<int>& nums, int difference, unordered_map<int, int>& freqMap, int i) {
        if (i == nums.size()) {
            return 1;
        }
        int totalCount = countBeautifulSubsets(nums, difference, freqMap,
                                               i + 1);

        if (!freqMap[nums[i] - difference]) {
            freqMap[nums[i]]++;
            totalCount += countBeautifulSubsets(nums, difference, freqMap,
                                                i + 1);
            freqMap[nums[i]]--;
        }

        return totalCount;
    }
};