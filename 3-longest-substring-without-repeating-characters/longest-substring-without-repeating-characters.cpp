class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int> mp;
        int s = 0;
        int maxSubarrayLen = 0;
        for (int e = 0; e < str.length(); ++e) {
            mp[str[e]]++;
            while (mp[str[e]] > 1) {
                mp[str[s]]--;
                if (mp[str[s]] == 0)
                    mp.erase(str[s]);
                ++s;
            }
            maxSubarrayLen = max(maxSubarrayLen, e - s + 1);
        }
        return maxSubarrayLen;
    }
};