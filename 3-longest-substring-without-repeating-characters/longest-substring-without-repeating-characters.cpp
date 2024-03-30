class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int> mp;
        int s = 0;
        int max_len = 0;
        for (int e = 0; e < str.length(); ++e) {
            mp[str[e]]++;
            while (mp[str[e]] > 1) {
                mp[str[s]]--;
                if (mp[str[s]] == 0)
                    mp.erase(str[s]);
                ++s;
            }
            max_len = max(max_len, e - s + 1);
        }
        return max_len;
    }
};