class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (mp.find(ch) != mp.end()) {
                mp[ch]++;
            } else {
                mp[ch] = 1;
            }
        }
        bool odd = false;
        for (auto& p : mp) {
            if (p.second % 2 == 0) {
                ans += p.second;
            } else {
                ans += p.second;
                if (!odd) {
                    odd = true;
                } else {
                    ans -= 1;
                }
            }
        }
        return ans;
    }
};