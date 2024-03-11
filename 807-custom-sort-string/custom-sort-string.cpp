class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (auto c : s)
            mp[c]++;
        string ans = "";

        for (auto c : order) {
            if (mp.find(c) != mp.end()) {
                int f = mp[c];
                while (f--) {
                    ans += c;
                }
                mp[c] = 0;
            }
        }
        for (auto c : s) {
            if (mp[c] != 0) {
                ans += c;
                mp[c]--;
            }
        }
        return ans;
    }
};