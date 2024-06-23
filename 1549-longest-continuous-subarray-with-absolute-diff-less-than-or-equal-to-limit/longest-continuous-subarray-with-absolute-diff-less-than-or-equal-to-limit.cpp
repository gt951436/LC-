class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int maxLen = 0;
        deque<int> maxQ, minQ;
        int s = 0;
        for (int e = 0; e < n; ++e) {
            while (!maxQ.empty() && nums[e] > maxQ.back()) {
                maxQ.pop_back();
            }
            maxQ.push_back(nums[e]);
            while (!minQ.empty() && nums[e] < minQ.back()) {
                minQ.pop_back();
            }
            minQ.push_back(nums[e]);

            while (maxQ.front() - minQ.front() > limit && !maxQ.empty() &&
                   !minQ.empty()) {
                if (nums[s] == maxQ.front()) {
                    maxQ.pop_front();
                }
                if (nums[s] == minQ.front()) {
                    minQ.pop_front();
                }
                ++s;
            }
            maxLen=max(maxLen,e-s+1);
        }
        return maxLen;
    }
};